/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** ObjectTriangle
*/

#ifndef OBJECTTRIANGLE_HPP
#define OBJECTTRIANGLE_HPP

#include "../../Data/MyVector/MyVector2.hpp"
#include "../../../include/ICollidable.hpp"

#include "export.hpp"

#include <functional>

using namespace raylib;

namespace ObjectType
{
    class EXPORT ObjectLine;
    class EXPORT ObjectBox;
    class EXPORT ObjectTriangle
    {
        public:
            ObjectTriangle(const MyVector2 a, const MyVector2 b, const MyVector2 c);
            ~ObjectTriangle();
            void setTriangle(const MyVector2 a, const MyVector2 b, const MyVector2 c);
            MyVector2 getPointA() const;
            MyVector2 getPointB() const;
            MyVector2 getPointC() const;

            bool boxCollider(const ObjectType::ObjectBox &box);

        private:
            MyVector2 _a;
            MyVector2 _b;
            MyVector2 _c;
    };
};

#endif