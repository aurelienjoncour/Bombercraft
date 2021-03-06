/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 27/05/2021 IComponentTypeRegister.hpp.h
*/

#ifndef ICOMPONENTTYPEREGISTER_HPP
#define ICOMPONENTTYPEREGISTER_HPP

#include <cstddef>
#include "entity.hpp"
#include "SaveManager/SaveManager.hpp"

namespace Engine
{
    class IComponentTypeRegister {
      public:
        virtual ~IComponentTypeRegister() = default;

        virtual void allocate(std::size_t size) = 0;
        virtual bool tryRemove(Entity entity) = 0;
    };
} // namespace Engine

#endif // ICOMPONENTTYPEREGISTER_HPP