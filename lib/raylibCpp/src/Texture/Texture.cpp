/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Texture
*/

#include "Texture.hpp"

raylib::Texture::Texture(const std::string &path, MyVector2 position,
RColor color)
{
    _path = path;
    _position = position;
    _color = color;
    _texture = LoadTexture(path.data());
}

raylib::Texture::~Texture()
{
    UnloadTexture(_texture);
}

void raylib::Texture::draw()
{
    DrawTexture(_texture, _position.a, _position.b, _matchingColors.at(_color));
}

void raylib::Texture::setPosition(MyVector2 position)
{
    _position = position;
}

void raylib::Texture::setColor(RColor color)
{
    _color = color;
}

void raylib::Texture::setPath(const std::string &path)
{
    _path = path;
    UnloadTexture(_texture);
    _texture = LoadTexture(path.data());
}

Texture2D raylib::Texture::getTexture() const
{
    return _texture;
}

std::string raylib::Texture::getPath() const
{
    return _path;
}