/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Include
*/

#ifndef INCLUDE_HPP
#define INCLUDE_HPP

#include <iostream>
#include <memory>
#include <stdexcept>

#include <unistd.h>
#include <stdlib.h>

#include <vector>
#include <array>
#include <map>
#include <unordered_map>

#include "raylib.h"
#include "raymath.h"

#include "../src/Data/Enum.hpp"
#include "../src/Data/Const.hpp"
#include "../src/Data/MyVector/MyVector2.hpp"
#include "../src/Data/MyVector/MyVector3.hpp"
#include "../src/Data/MyVector/MyVector4.hpp"

#if defined(PLATFORM_DESKTOP)
    #define GLSL_VERSION 330
#else // PLATFORM_RPI, PLATFORM_ANDROID, PLATFORM_WEB
    #define GLSL_VERSION 100
#endif

typedef std::string string;
typedef std::size_t size_t;
typedef std::stringstream stringstream;
typedef std::fstream fstream;
typedef std::ofstream ofstream;
typedef std::ifstream ifstream;
#define charette_ptr(T) std::shared_ptr<T>
#define toString(str)   std::to_string(str)
#define toInteger(str)  std::stoi(str)
#define toSize_t(str)   std::stoul(str)

#endif // INCLUDE_HPP