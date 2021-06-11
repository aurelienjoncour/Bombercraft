/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 11/06/2021 StringChoice.cpp.cc
*/

#include "StringChoice.hpp"

Component::StringChoice::StringChoice(const std::vector<std::string> &choices)
    : _idx(0), _choices(choices)
{
    if (choices.empty()) {
        throw std::invalid_argument("StringChoice empty choices.");
    }
}

std::string Component::StringChoice::get() const
{
    return _choices[_idx];
}

void Component::StringChoice::next()
{
    if (_idx == (_choices.size() - 1)) {
        _idx = 0;
    } else {
        _idx++;
    }
}

void Component::StringChoice::prev()
{
    if (_idx == 0) {
        _idx = _choices.size() - 1;
    } else {
        _idx--;
    }
}
