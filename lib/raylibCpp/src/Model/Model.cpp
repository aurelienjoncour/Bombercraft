/*
** EPITECH PROJECT, 2021
** IndieStudio
** File description:
** Model
*/

#include "Model.hpp"

raylib::Model::Model(const std::shared_ptr<ITexture> texture, const string &filepath, const MyVector3 position = {0, 0, 0},
    const RColor color = RColor::RWHITE)
{
    _position = position;
    _rotation = {0.0f, 0.0f, 0.0f};
    _scale = 1.0f;
    _color = color;
    _texture = texture;
    _path = filepath;
    _model = LoadModel(filepath.data());
}

raylib::Model::~Model()
{
    UnloadModel(_model);
}

void raylib::Model::draw()
{
    Vector3 rayPos = {_position.a, _position.b, _position.c};

    DrawModel(_model, rayPos, _scale, _matchingColors.at(_color));
}

void raylib::Model::setPosition(const MyVector3 position)
{
    _position = position;
}

void raylib::Model::setRotation(const MyVector3 rotation)
{
    float pitch = rotation.a;
    float yam = rotation.b;
    float roll = rotation.c;

    _rotation = rotation;
    _model.transform = MatrixRotateXYZ((Vector3){DEG2RAD * pitch, DEG2RAD * yam, DEG2RAD * roll});
}

void raylib::Model::setScale(const float scale)
{
    _scale = scale;
}

void raylib::Model::setColor(const RColor color)
{
    _color = color;
}

void raylib::Model::setPath(const string &path)
{
    float pitch = _rotation.a;
    float yam = _rotation.b;
    float roll = _rotation.c;

    _path = path;
    UnloadModel(_model);
    _model = LoadModel(path.data());
    _model.transform = MatrixRotateXYZ((Vector3){DEG2RAD * pitch, DEG2RAD * yam, DEG2RAD * roll});
}

void raylib::Model::setTexture(const std::shared_ptr<ITexture> &texture)
{
    _texture = texture;
    SetMaterialTexture(&_model.materials[0], MAP_DIFFUSE, texture->getTexture());
}

string raylib::Model::getPath() const
{
    return _path;
}