/*
** EPITECH PROJECT, 2021
** PreloadGamesSaveMenuScene.cpp
** File description:
** Create buttons to display information about loadable games
*/

#include "SaveMenuScene.hpp"
#include "Game/Core/Core.hpp"
#include "Utilities/ProportionUtilities.hpp"
#include "GUI/Factories/Button/ButtonFactory.hpp"

extern std::unique_ptr<Game::Core> core;

void Game::SaveMenuScene::createButtonGamePreload(const std::filesystem::path &dir, const size_t entryNb)
{
    const ProportionUtilities my_utility(CoreData::settings->getMyVector2("WIN_SIZE"));
    const GUI::ButtonConfig my_config(GUI::ButtonFactory::getBighHighButtonConfig());
    raylib::MyVector2 my_position(my_utility(25, 20));
    std::string my_screenshotPath(dir.string() + "/GameShot.png");
    my_position.b += (float) (my_config.size.b * 1.3) * (float) entryNb;

    if (my_position.b > my_utility.getProportion(100, 80).b) {
        my_position = my_utility(75, 20);
        my_position.b += (float) (my_config.size.b * 1.3)
            * (float) (entryNb - ((size_t) (my_utility.getProportion(100, 60).b / my_config.size.b)));
        if (my_position.b > my_utility.getProportion(100, 80).b) {
            return;
        }
    }
    GUI::ButtonFactory::create(
        this->localEntities,
        my_position,
        my_config,
        [dir](const Engine::Entity &) {
            const Engine::Entity &optionEntity = core->globalEntities.getEntity("options");
            auto &options = CoreData::entityManager->getComponent<Component::OptionComponent>(optionEntity);

            options.loadName = dir.filename();
            CoreData::sceneManager->popLastScene();
            CoreData::sceneManager->setScene<GameScene>();
        },
        my_screenshotPath,
        dir.filename(),
        true);
}

void Game::SaveMenuScene::preLoadGames()
{
    // TODO create entities : save selector
    //  with
    //      name (directory name)
    //      screenshot (in directory)
    //      date (of the directory)
    const auto my_dir(CoreData::entityManager->saveManager.listWD());
    size_t entryNb(0);

    for (const auto &entry : my_dir) {
        if (entry.is_directory()) {
            createButtonGamePreload(entry, entryNb);
            entryNb++;
        }
    }
}