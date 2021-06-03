/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 02/06/2021 Core.cpp.cc
*/

#include "Core.hpp"

using namespace Game;

static const std::string CONFIG_FILE = "bomberman.config";

static const MyVector3 CAM_POSITION = {300, 0, 100};
static const MyVector3 CAM_TARGET = {0, 0, 0};
static const MyVector3 CAM_UP = {0, 1, 0};

std::unique_ptr<raylib::Camera> Core::camera = std::make_unique<raylib::Camera>(CAM_POSITION, CAM_TARGET, CAM_UP);

Core::Core()
    : _settings(CONFIG_FILE), _window(_settings.getMyVector2("WIN_SIZE"), _settings.getString("WIN_TITLE"), static_cast<RColor>(_settings.getInt("WIN_BACK"))),
    _entityManager(_systemManager), _sceneManager(_entityManager)
{
    /// COMPONENTS - DEFINITION
    _entityManager.registerComponent<Component::Render2D>();
    _entityManager.registerComponent<Component::Render3D>();
    /// SYSTEMS - CREATION
    _systemManager.createSystem<System::Render3DSystem>(_entityManager);
    _systemManager.createSystem<System::Render2DSystem>(_entityManager);
    // SCENES - CREATION
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
