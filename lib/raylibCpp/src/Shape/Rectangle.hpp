/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Rectangle
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "../../include/object.hpp"

#include "IShape.hpp"

#include "export.hpp"

namespace raylib
{
    class EXPORT Rectangle : public IShape {
      public:
        Rectangle(const MyVector2 position, const MyVector2 size, const RColor color = RColor::RWHITE);
        ~Rectangle() = default;

        void draw();

        void setPosition(const MyVector2 position);
        void setSize(const MyVector2 size);
        void setColor(const RColor color);

      private:
        MyVector2 _position;
        MyVector2 _size;
        RColor _color;
    };
}; // namespace raylib

#endif // RECTANGLE_HPP