/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ObjectCircle
*/

#ifndef OBJECTCIRCLE_HPP
#define OBJECTCIRCLE_HPP

#include "../Collision.hpp"
#include "../../Data/MyVector/MyVector2.hpp"
#include "../../../include/ICollidable.hpp"

#include <functional>

namespace raylib
{
    class ObjectRectangle;
    class ObjectBox;
    class ObjectCircle : public ICollidable {
      public:
        ObjectCircle(const MyVector2 center, const float radius);
        ~ObjectCircle();
        void setCircle(const MyVector2 center, const float radius);
        MyVector2 getCircleCenter() const;
        float getCircleRadius() const;
        bool checkCollisionWith(const ObjectCircle &circle);
        bool checkCollisionWith(const ObjectRectangle &rectangle);

        bool boxCollider(const ObjectBox &box);

      private:
        MyVector2 _center;
        float _radius;
    };
}; // namespace raylib

#endif