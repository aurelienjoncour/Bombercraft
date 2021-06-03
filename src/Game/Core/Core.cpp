/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 02/06/2021 Core.cpp.cc
*/

#include "Core.hpp"

using namespace Game;

static const MyVector2 WIN_SIZE = {800, 600};
static const std::string WIN_TITLE = "BomberBlock";
static const RColor WIN_BACK = RColor::RBLACK;

static const MyVector3 CAM_POSITION = {300, 0, 100};
static const MyVector3 CAM_TARGET = {0, 0, 0};
static const MyVector3 CAM_UP = {0, 1, 0};

std::unique_ptr<raylib::Camera> Core::camera = std::make_unique<raylib::Camera>(CAM_POSITION, CAM_TARGET, CAM_UP);

Core::Core()
    : _window(WIN_SIZE, WIN_TITLE, WIN_BACK), _entityManager(_systemManager), _sceneManager(_entityManager)
{
    /// COMPONENTS
    _entityManager.registerComponent<Component::Render2D>();
    _entityManager.registerComponent<Component::Render3D>();
    /// SYSTEMS
    _systemManager.createSystem<System::Render3DSystem>(_entityManager);
    _systemManager.createSystem<System::Render2DSystem>(_entityManager);
    /// ENTITIES
    auto rect = _entityManager.createEntity();
    _entityManager.addComponent<Component::Render2D>(rect,
        std::make_shared<raylib::Rectangle>((raylib::MyVector2){10, 10}, (raylib::MyVector2){20, 20})
    );
    auto block = _entityManager.createEntity();
    _entityManager.addComponent<Component::Render3D>(block,
        std::make_shared<raylib::Cuboid>(nullptr, (raylib::MyVector3){50, 50, 0}, (raylib::MyVector3){50, 50, 50}, raylib::RColor::RRED)
    );
    // SCENES
    _sceneManager.createScene<DebugScene>(_systemManager, _entityManager);
}

Core::~Core()
{
}

void Core::loop()
{
    _window.open();
    while (_window.isOpen()) {
        _window.clear();
        _sceneManager.run();
        _window.refresh();
    }
    _window.close();
}
