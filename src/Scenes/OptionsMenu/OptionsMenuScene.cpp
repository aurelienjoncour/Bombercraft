/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** OptionsMenuScene
*/

#include <sstream>
#include "OptionsMenuScene.hpp"
#include "Scenes/SoundOption/SoundOptionScene.hpp"
#include "Scenes/SkinChoice/SkinChoiceScene.hpp"
#include "Utilities/ProportionUtilities.hpp"

using namespace Game;

OptionsMenuScene::OptionsMenuScene(Engine::SystemManager &systemManager)
    : Engine::AbstractScene(systemManager, *CoreData::entityManager)
{
}

void OptionsMenuScene::open()
{
    ProportionUtilities my_utility(Game::CoreData::settings->getMyVector2("WIN_SIZE"));

    const std::vector<raylib::MyVector2> buttonPosition({
        my_utility.getProportion(25, 20),
        my_utility.getProportion(75, 20),
        my_utility.getProportion(25, 30),
        my_utility.getProportion(75, 30),
        my_utility.getProportion(25, 40),
        my_utility.getProportion(75, 40),
        my_utility.getProportion(25, 50),
        my_utility.getProportion(50, 90),
    });

    auto scene = CoreData::sceneManager->getCurrentScene();
    const GUI::ButtonConfig bigButton = GUI::ButtonFactory::getBigButtonConfig();
    const GUI::ButtonConfig doneButton = GUI::ButtonFactory::getMediumButtonConfig();

    // BACKGROUND
    GUI::ImageFactory::create(scene->localEntities,
        raylib::MyVector2(0, 0),
        CoreData::settings->getMyVector2("WIN_SIZE"),
        CoreData::settings->getString("STANDARD_BACKGROUND"),
        false);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[0],
        "skin",
        bigButton,
        "Skin Customization",
        [](const Engine::Entity) {
            CoreData::sceneManager->pushLastScene();
            CoreData::sceneManager->setScene<SkinChoiceScene>();
        },
        true);

    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[1],
        "music",
        bigButton,
        "Music & Sounds",
        [](const Engine::Entity) {
            CoreData::sceneManager->pushLastScene();
            CoreData::sceneManager->setScene<SoundOptionScene>();
            std::cout << "Music & Sounds" << std::endl;
        },
        true);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[2],
        "video settings",
        bigButton,
        "Video Settings",
        [](const Engine::Entity) {
            std::cout << "Video settings" << std::endl;
        },
        true);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[3],
        "controls",
        bigButton,
        "Controls...",
        [](const Engine::Entity) {
            CoreData::sceneManager->pushLastScene();
            CoreData::sceneManager->setScene<KeyBindingMenuScene>();
        },
        true);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[4],
        "ressourcepack",
        bigButton,
        "Ressource Pack",
        [](const Engine::Entity) {
            std::cout << "Ressource Pack" << std::endl;
        },
        true);
    GUI::SliderFactory::create(
        this->localEntities,
        buttonPosition[5],
        [](const Engine::Entity entity, GUI::sliderValue &value) {
            std::cout << "Slider: entity=" << entity << ", value=" << value << std::endl;
        },
        "FOV: ",
        bigButton.size,
        0,
        200,
        60,
        true);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[6],
        "Rate",
        bigButton,
        "Rate Us",
        [](const Engine::Entity) {
            const std::string rateURL = Game::CoreData::settings->getString("RATE_URL");
            CoreData::window->openURL(rateURL);
        },
        true);
    GUI::ButtonFactory::create(
        scene->localEntities,
        buttonPosition[7],
        "done",
        doneButton,
        "Done",
        [](const Engine::Entity) {
            CoreData::sceneManager->setScene(CoreData::sceneManager->peekLastScene());
        },
        true);
}

void Game::OptionsMenuScene::update()
{
    auto &render2D = this->_systemManager.getSystem<System::Render2DSystem>();

    render2D.update();
    this->eventDispatcher(this->_systemManager);
}