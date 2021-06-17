/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** Bomb
*/

#include "Game/Factories/Block/BlockFactory.hpp"
#include "BombFactory.hpp"
#include "Components/Matrix2D/Matrix2D.hpp"
#include "Components/ModelList/ModelList.hpp"
#include "Game/CoreData/CoreData.hpp"

using namespace GUI;

bool BombFactory::isBombPlacable(float posX, float posY)
{
    auto map(Game::CoreData::entityManager->getComponent<Component::Matrix2D>(
        Game::CoreData::sceneManager->getCurrentScene()->localEntities.getEntity("gameMap")));
    auto my_data(map.getData(std::make_pair(static_cast<size_t>(posX), static_cast<size_t>(posY))));

    if (my_data.second == GUI::BlockFactory::BlockType::BLOCK_AIR) {
        return true;
    }
    return false;
}

raylib::MyVector2 BombFactory::getNextPos(const raylib::MyVector2 &position, const float rotation)
{
    auto my_position(position);

    if (rotation == 0)
        my_position.b++;
    if (rotation == 90)
        my_position.a--;
    if (rotation == 180)
        my_position.b--;
    if (rotation == 270)
        my_position.a++;
    return my_position;
}

bool BombFactory::placeBomb(Engine::Entity character)
{
    Component::ModelList &render = Game::CoreData::entityManager->getComponent<Component::ModelList>(character);
    const Component::Hitbox &hitbox = Game::CoreData::entityManager->getComponent<Component::Hitbox>(character);
    auto characterOrientation(render.getRotation().b);
    auto characterPosition(hitbox.objectBox->getBoxOrigin() + hitbox.objectBox->getBoxSize() / 2);
    auto bombIndexOnMap(getNextPos(Component::Matrix2D::getMapIndex(characterPosition), characterOrientation));
    const auto bombPosition(Component::Matrix2D::getPositionAbs((size_t) bombIndexOnMap.a, (size_t) bombIndexOnMap.b));
    Component::PlayerInventory &playerInventory =
        Game::CoreData::entityManager->getComponent<Component::PlayerInventory>(character);
    const Component::PlayerInventoryInfo &inventoryInfo = playerInventory.getPlayerInventoryInfo();

    if (inventoryInfo.bomb && isBombPlacable(bombIndexOnMap.a, bombIndexOnMap.b)) {
        playerInventory.setBomb(inventoryInfo.bomb - 1);
        GUI::BombFactory::create(Game::Core::sceneManager->getCurrentScene()->localEntities, bombPosition, character);
        render.select("setBomb");
        return true;
    }
    return false;
}

Engine::Entity BombFactory::create(
    Engine::EntityPack &entityPack, const raylib::MyVector3 position, Engine::Entity entityParent, const std::string &name)
{
    Engine::Entity entityMap = Game::CoreData::sceneManager->getCurrentScene()->localEntities.getEntity("gameMap");
    const Component::Matrix2D &matrix = Game::CoreData::entityManager->getComponent<Component::Matrix2D>(entityMap);
    const raylib::MyVector3 &size = Game::CoreData::settings->getMyVector3("STANDARD_BLOCK_SIZE");
    std::shared_ptr<raylib::Animation> animation = BombFactory::getAnimation(position);
    raylib::MyVector2 positionOnMap = Component::Matrix2D::getMapIndex(position);
    Engine::Entity entity = (name.size()) ? entityPack.createEntity(name) : entityPack.createAnonymousEntity();
    int bombCountdown = Game::CoreData::settings->getInt("BOMB_COUNTDOWN");


    matrix.getData()->save({(size_t)positionOnMap.a, (size_t)positionOnMap.b}, entity, GUI::BlockFactory::BlockType::BLOCK_BOMB);
    Game::CoreData::entityManager->addComponent<Engine::Position>(entity, position.a, position.b, position.c);
    Game::CoreData::entityManager->addComponent<Component::Render3D>(entity, animation);
    if (bombCountdown < 0)
        bombCountdown = 0;
    Game::CoreData::entityManager->addComponent<Component::Hitbox>(
        entity, position, size, BombFactory::handlerBombCollision, Game::EntityType::BOMB);
    Game::CoreData::entityManager->addComponent<Engine::Timer>(
        entity, bombCountdown, *Game::CoreData::entityManager, *Game::CoreData::sceneManager, BombFactory::handlerBombTimer);
    Game::CoreData::entityManager->addComponent<Engine::EntityBox>(entity, entityParent);
    return entity;
}

std::shared_ptr<raylib::Animation> BombFactory::getAnimation(const raylib::MyVector3 &pos)
{
    std::string animationPath = Game::CoreData::settings->getString("BOMB_ANIM");
    std::string typeInStr = "BOMB";
    std::string texturePath = Game::CoreData::settings->getString("BOMB_ANIM_TEXTURE");

    return std::make_shared<raylib::Animation>(texturePath, animationPath, pos, raylib::RColor::RWHITE);
}

void BombFactory::handlerBombCollision(const Engine::Entity &fromEntity, const Engine::Entity &toEntity)
{
    // TODO stop moving
    (void) fromEntity;
    (void) toEntity;
}

void BombFactory::handlerBombTimer(
    Engine::EntityManager &entityManager, Engine::SceneManager &sceneManager, const Engine::Entity &entity)
{
    auto scene = Game::Core::sceneManager->getCurrentScene();
    Engine::Position &pos = entityManager.getComponent<Engine::Position>(entity);
    Engine::EntityBox &player = entityManager.getComponent<Engine::EntityBox>(entity);
    Component::PlayerInventory &playerInventory = entityManager.getComponent<Component::PlayerInventory>(player.entity);
    const Component::PlayerInventoryInfo &inventoryInfo = playerInventory.getPlayerInventoryInfo();

    playerInventory.setBomb(inventoryInfo.bomb + 1);
    BlockFactory::blastPropagation(pos, sceneManager.getCurrentScene()->localEntities, inventoryInfo.blastRadius);
    scene->localEntities.removeEntity(entity);
}