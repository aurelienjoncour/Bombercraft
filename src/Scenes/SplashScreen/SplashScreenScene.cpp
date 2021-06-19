/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 03/06/2021 SplashScreenScene.cpp.cc
*/

#include "SplashScreenScene.hpp"
#include "Systems/Hitbox/HitboxSystem.hpp"
#include "Components/Hitbox/Hitbox.hpp"
#include "GUI/Factories/Checkbox/CheckboxFactory.hpp"
#include "GUI/Factories/Countdown/CountdownFactory.hpp"
#include "GUI/Factories/Image/ImageFactory.hpp"
#include "GUI/Factories/Image/ImageSequenceFactory.hpp"

using namespace Game;

static const EventRequirement keyHandlerRequirements({raylib::KeyBoard::IKEY_SPACE}, {});

static Component::eventScript keyHandler = [](const Engine::Entity) {
    CoreData::sceneManager->setScene<MainMenuScene>();
};

SplashScreenScene::SplashScreenScene(Engine::SystemManager &systemManager)
    : AbstractScene(systemManager, *Game::CoreData::entityManager)
{
}

void SplashScreenScene::open()
{
    const raylib::MyVector2 windowSize(CoreData::settings->getMyVector2("WIN_SIZE"));

    GUI::ImageSequenceFactory::create(this->localEntities,
        {0, 0},
        {windowSize.a, windowSize.b},
        "Asset/SplashScreen",
        "splashScreen",
        0.05f,
        false);
    this->_entityManager.addComponent<Component::KeyEvent>(
        this->localEntities.getEntity("splashScreen"), keyHandler, keyHandlerRequirements);
    Engine::Entity entity = this->localEntities.createEntity("Text");
    this->_entityManager.addComponent<Component::Render2D>(entity,
        Component::render2dMapModels({
            {"text",
                std::make_shared<raylib::Text>("Press SPACE to start",
                    "Asset/Font/Code-Bold.ttf",
                    ProportionUtilities::getProportionWin(windowSize, {2, 96}),
                    30,
                    raylib::RColor::RBLACK)},
        }));
}

void SplashScreenScene::update()
{
    auto &render2D = this->_systemManager.getSystem<System::Render2DSystem>();
    auto &timer = this->_systemManager.getSystem<Engine::TimerSystem>();

    render2D.update();
    timer.update();
    this->eventDispatcher(this->_systemManager);
}