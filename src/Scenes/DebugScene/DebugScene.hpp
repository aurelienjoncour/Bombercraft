/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 03/06/2021 DebugScene.hpp.h
*/

#ifndef DEBUGSCENE_HPP
#define DEBUGSCENE_HPP

#include "GameEngine.hpp"
#include "Systems/Render2D/Render2DSystem.hpp"
#include "Systems/Render3D/Render3DSystem.hpp"
#include "Scenes/SceneWithEvents/SceneWithEvents.hpp"
#include "Game/EventRequirement/EventRequirement.hpp"

namespace Game
{
    class DebugScene : public Engine::AbstractScene, public SceneWithEvents {
      public:
        DebugScene(Engine::SystemManager &systemManager, Engine::EntityManager &entityManager, raylib::Input &eventManager);
        ~DebugScene() = default;

        void update();
    };
}

#endif // DEBUGSCENE_HPP
