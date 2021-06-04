/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 03/06/2021 Event.hpp.h
*/

#ifndef CLICKEVENT_HPP
#define CLICKEVENT_HPP

#include "Components/AbstractEvent/AbstractEvent.hpp"
#include "GameEngine.hpp"

namespace Component {
    class ClickEvent : public AbstractEvent, public Engine::Component<ClickEvent> {
      public:
        ClickEvent(Engine::SceneManager &sceneManager, eventScript &handler,
            Game::EventRequirement &requirements)
            : AbstractEvent(sceneManager, handler, requirements)
        {}
    };
}

#endif // CLICKEVENT_HPP