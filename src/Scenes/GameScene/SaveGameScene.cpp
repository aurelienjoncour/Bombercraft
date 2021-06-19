/*
** EPITECH PROJECT, 2021
** SaveGameScene.cpp
** File description:
** Save state of entities in GameScene to save
*/

#include "GameScene.hpp"

using namespace Game;

extern std::unique_ptr<Game::Core> core;

void GameScene::savePlayerConfig()
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
        my_xp = config[i]->getXP();
        my_filename = configName_prefix + toString(i + 1);
        try {
            if (!CoreData::entityManager->saveManager.fileExistsInWD(my_filename))
                CoreData::entityManager->saveManager.createFile(my_filename);
            CoreData::entityManager->saveManager.setWritingFile(my_filename);
            CoreData::entityManager->saveManager.writeActFile(my_xp);
            // TODO ajouter toutes les variables de playerConfig à la suite
            CoreData::entityManager->saveManager.closeWritingFile(my_filename);
        } catch (const std::filesystem::filesystem_error &my_e) {
            std::cerr << my_e.what() << std::endl;
        }
    }
}

void GameScene::saveGame(const std::string &saveName)
{
    try {
        if (!CoreData::entityManager->saveManager.directoryExistsInWD(saveName))
            CoreData::entityManager->saveManager.createDirectory(saveName);
        CoreData::entityManager->saveManager.setWorkingDirectory(saveName);
    } catch (const std::filesystem::filesystem_error &my_e) {
        Engine::SaveManager::printException(my_e);
        return;
    }
    savePlayerConfig();
    CoreData::entityManager->saveManager.unsetWorkingDirectory();
}