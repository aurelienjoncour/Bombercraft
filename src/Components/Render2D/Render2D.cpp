/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 02/06/2021 Render2D.cpp.cc
*/

#include "Render2D.hpp"

using namespace Component;

Render2D::Render2D(render2dMapModels const &models)
{
    for (auto [label, model] : models) {
        if (this->_modelIndex.find(label) != this->_modelIndex.end()) {
            throw std::invalid_argument("in Render2D::Render2D, Label index "
                                        "already exists");
        }
        std::size_t index = this->_models.size();
        this->_modelIndex[label] = index;
        this->_labelIndex[index] = label;
        this->_modelsToDrawIndex.insert(index);
        this->_models.push_back(model);
    }
}

void Render2D::draw()
{
    for (auto &index : _modelsToDrawIndex) {
        _models.at(index)->draw();
    }
}

void Render2D::add(std::shared_ptr<raylib::IRenderable> model, const std::string &label)
{
    if (this->_modelIndex.find(label) != this->_modelIndex.end()) {
        throw std::invalid_argument("in Render2D::add, Label index already "
                                    "exists");
    }
    std::size_t index = this->_models.size();
    this->_modelIndex[label] = index;
    this->_labelIndex[index] = label;
    this->_modelsToDrawIndex.insert(index);

    this->_models.push_back(model);
}

void Render2D::remove(const std::string &label)
{
    if (this->_modelIndex.find(label) == this->_modelIndex.end()) {
        throw std::invalid_argument("in Render2D::remove, undefined label "
                                    "index");
    }
    std::size_t index = this->_modelIndex[label];
    this->_modelIndex.erase(label);

    std::size_t indexLast = _models.size() - 1;
    std::string labelLast = this->_labelIndex[indexLast];
    if (index != indexLast) {
        this->_models[index] = this->_models.back();
        this->_modelIndex[labelLast] = index;
        this->_labelIndex[index] = labelLast;
    } else {
        this->_models.pop_back();
    }
    _modelsToDrawIndex.erase(index);
    this->_labelIndex.erase(indexLast);
}

std::shared_ptr<raylib::IRenderable> &Render2D::get(const std::string &label)
{
    if (this->_modelIndex.find(label) == this->_modelIndex.end()) {
        throw std::invalid_argument("in Render2D::get, Undefined label \"" + label + "\"");
    }
    return this->_models[_modelIndex[label]];
}

bool Render2D::doesGet(const std::string &label)
{
    return this->_modelIndex.find(label) != this->_modelIndex.end();
}

void Render2D::setToDrawFirst(const string &label)
{
    const auto &my_index(_modelIndex.at(label));

    _modelsToDrawIndex.insert(_modelsToDrawIndex.begin(), my_index);
}

void Render2D::setToDrawLast(const string &label)
{
    const auto &my_index(_modelIndex.at(label));

    _modelsToDrawIndex.insert(_modelsToDrawIndex.end(), my_index);
}

void Render2D::unsetToDraw(const string &label)
{
    _modelsToDrawIndex.erase(_modelIndex.at(label));
}

bool Render2D::isSetToDraw(const std::string &label) const
{
    return this->_modelsToDrawIndex.find(this->_modelIndex.at(label)) != this->_modelsToDrawIndex.end();
}