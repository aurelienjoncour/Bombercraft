/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 10/06/2021 SoundComponent.cpp.cc
*/

#include "Sound.hpp"

Component::Sound::Sound(std::shared_ptr<raylib::IAudio> audio, bool isMusic) : audio(audio), isMusic(isMusic)
{
}