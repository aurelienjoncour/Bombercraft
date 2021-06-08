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
#include <memory>

namespace Component
{
    class ClickEvent : public AbstractEvent, public Engine::Component<ClickEvent> {
      public:
        explicit ClickEvent(eventScript &handler);
    };
} // namespace Component

#endif // CLICKEVENT_HPP