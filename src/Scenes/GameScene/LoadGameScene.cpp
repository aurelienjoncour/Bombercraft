/*
** EPITECH PROJECT, 2021
** LoadGameScene.cpp
** File description:
** Load state of entities in GameScene from file
*/

#include "GameScene.hpp"

using namespace Game;

extern std::unique_ptr<Game::Core> core;

void GameScene::loadPlayerConfig()
{
    size_t my_xp;
    const auto configName_prefix("config");
    std::string my_filename;
    Component::PlayerConfig *config[MAX_PLAYERS] = {&CoreData::entityManager->getComponent<Component::PlayerConfig>(
                                                        core->globalEntities.getEntity(configName_prefix + toString(1))),
        &CoreData::entityManager->getComponent<Component::PlayerConfig>(
            core->globalEntities.getEntity(configName_prefix + toString(2))),
        &CoreData::entityManager->getComponent<Component::PlayerConfig>(
            core->globalEntities.getEntity(configName_prefix + toString(3))),
        &CoreData::entityManager->getComponent<Component::PlayerConfig>(
            core->globalEntities.getEntity(configName_prefix + toString(4)))};

    for (size_t i = 0; i < 4; i++) {
        my_xp = 0;
        my_filename = configName_prefix + toString(i + 1);
        try {
            if (!CoreData::entityManager->saveManager.fileExistsInWD(my_filename))
                continue;
            CoreData::entityManager->saveManager.setReadingFile(my_filename);
            CoreData::entityManager->saveManager.readActFile(my_xp);
            CoreData::entityManager->saveManager.closeReadingFile(my_filename);
        } catch (const std::filesystem::filesystem_error &my_e) {
            std::cerr << my_e.what() << std::endl;
            continue;
        }
        config[i]->setXP(my_xp);
        std::cout << "my_xp loaded : " << my_xp << std::endl;
    }
}

void GameScene::loadGame(const std::string &loadName)
{
    try {
        CoreData::entityManager->saveManager.setWorkingDirectory(loadName);
    } catch (const std::filesystem::filesystem_error &my_e) {
        std::cerr << my_e.what() << std::endl;
        return;
    }
    loadPlayerConfig();
    CoreData::entityManager->saveManager.unsetWorkingDirectory();
}