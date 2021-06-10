/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 09/06/2021 ImageFactory.cpp.cc
*/

#include "ImageFactory.hpp"
#include "Game/CoreData/CoreData.hpp"
#include "Components/Render2D/Render2D.hpp"

void GUI::ImageFactory::create(Engine::EntityPack &entityPack, const raylib::MyVector2 &position, const raylib::MyVector2 &size,
    const std::string &filePath, const std::string &name)
{
    Engine::Entity entity;

    if (name.empty()) {
        entity = entityPack.createAnonymousEntity();
    } else {
        entity = entityPack.createEntity(name);
    }
    Game::CoreData::entityManager->addComponent<Component::Render2D>(entity,
        Component::render2dMapModels{{"image", std::make_shared<raylib::Texture>(filePath, size, position)}});
}
