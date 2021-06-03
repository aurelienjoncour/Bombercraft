/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Sound
*/

#ifndef SOUND_HPP
#define SOUND_HPP

#include "../../include/object.hpp"

#include "IAudio.hpp"

#include "export.hpp"

typedef Sound RSound;

namespace raylib
{
    class EXPORT Sound : public IAudio
    {
        public :
            Sound(const std::string &path, const float volume = 100, const float pitch = 100);
            ~Sound();

            void play();
            void stop();
            void resume();
            void pause();
            void update();

            void setPath(const std::string &path);
            void setVolume(const float volume);
            void setPitch(const float pitch);

        private :
            std::string _path;
            float _volume;
            float _pitch;
            RSound _sound;
    };
}; // namespace raylib

#endif // SOUND_HPP