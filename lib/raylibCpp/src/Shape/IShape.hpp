/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** IShape
*/

#ifndef ISHAPE_HPP
#define ISHAPE_HPP

#include "../../include/include.hpp"

#include "../Texture/ITexture.hpp"

namespace raylib
{
    class IShape
    {
        public :
            virtual ~IShape() {};

            virtual void draw() = 0;

            virtual void setPosition(MyVector2 position) = 0;
            virtual void setSize(MyVector2 size) = 0;
            virtual void setColor(RColor color) = 0;
    };
};

#endif // ISHAPE_HPP