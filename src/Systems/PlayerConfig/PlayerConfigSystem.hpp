/*
 * EPITECH PROJECT, 2021
 * PlayerConfig
 * File description:
 * PlayerConfigSystem.hpp - Created: 11/06/2021
 */

#ifndef PLAYER_CONFIG_SYSTEM_HPP
#define PLAYER_CONFIG_SYSTEM_HPP

#include "GameEngine.hpp"
#include "Components/PlayerConfig/PlayerConfig.hpp"

namespace System
{
    class PlayerConfigSystem : public Engine::AbstractSystem {
      public:
        PlayerConfigSystem();

        Component::PlayerConfig &update(const uint playerId) const;
        const std::vector<Component::PlayerConfig> update() const;
        Component::PlayerConfig &update(const Component::PlayerConfig &playerConfig) const;
    };
} // namespace System

#endif