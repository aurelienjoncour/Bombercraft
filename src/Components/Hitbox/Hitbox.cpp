/*
 * EPITECH PROJECT, 2021
 * Hitbox
 * File description:
 * Hitbox.cpp - Created: 03/06/2021
 */

#include "Hitbox.hpp"

using namespace Component;

Hitbox::Hitbox(const raylib::MyVector3 &origin, const raylib::MyVector3 &size, hitboxHandler handler)
    : objectBox(std::make_shared<ObjectBox>(origin, size)), _handler(handler)
{
}

void Hitbox::trigger(const Engine::Entity &fromEntity, const Engine::Entity &toEntity)
{
    this->_handler(fromEntity, toEntity);
}