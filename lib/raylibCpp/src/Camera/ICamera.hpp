/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ICamera
*/

#ifndef ICAMERA_HPP
#define ICAMERA_HPP

#include "../../include/object.hpp"

namespace raylib
{
    class ICamera {
      public:
        virtual ~ICamera() = default;

        virtual void begin3D() = 0;
        virtual void end3D() = 0;

        virtual const float &getFovy() const = 0;

        virtual void setPosition(const MyVector3 position) = 0;
        virtual void setTarget(const MyVector3 position) = 0;
        virtual void setUp(const MyVector3 position) = 0;
        virtual void setFovy(const float fovy) = 0;
    };
}; // namespace raylib

#endif // ICAMERA_HPP