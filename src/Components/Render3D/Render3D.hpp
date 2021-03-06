/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 02/06/2021 Render2DSystem.hpp.h
*/

#ifndef RENDER3D_HPP
#define RENDER3D_HPP

#include <memory>
#include "GameEngine.hpp"
#include "raylib.hpp"

namespace Component
{
    class Render3D : public Engine::Component<Render3D> {
      public:
        Render3D(std::shared_ptr<raylib::I3DObject> object);
        virtual ~Render3D() = default;

        std::shared_ptr<raylib::I3DObject> modele;
    };
} // namespace Component

#endif // RENDER3D_HPP