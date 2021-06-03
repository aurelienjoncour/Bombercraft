/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 27/05/2021 Component.hpp.h
*/

#ifndef COMPONENT_HPP
#define COMPONENT_HPP

#include <cstdlib>
#include <cctype>

namespace Engine
{
    template <typename T>
    class Component {
      public:
        Component() = default;
        ~Component() = default;

        /**
          * type : index of the bit (bitset) that identify the component in the Signature (entity.hpp)
         */
        static const std::size_t type;
    };

    std::size_t generateComponentType();

    template <typename T>
    const std::size_t Component<T>::type = Engine::generateComponentType();
}

#endif // COMPONENT_HPP
