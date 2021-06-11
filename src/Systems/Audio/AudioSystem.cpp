/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 10/06/2021 AudioSystem.cpp.cc
*/

#include "AudioSystem.hpp"
#include "Game/CoreData/CoreData.hpp"
#include "Components/Sound/Sound.hpp"

using namespace System;

AudioSystem::AudioSystem() : AbstractSystem(*Game::CoreData::entityManager)
{
    this->setRequirements<Component::Sound>();
}

void AudioSystem::play(std::string const& entityName)
{
    auto scene = Game::CoreData::sceneManager->getCurrentScene();
    if (scene == nullptr) {
        return;
    }
    Engine::EntityPack &scenePack = scene->localEntities;
    try {
        Engine::Entity soundEntity = scenePack.getEntity(entityName);

        if (_entityManager.hasComponent<Component::Sound>(soundEntity) == false) {
            std::cerr << "Warning: AudioSystem::update entity " << entityName << " does not have a Sound component." << std::endl;
        } else {
            auto sound = _entityManager.getComponent<Component::Sound>(soundEntity);

            if (sound.isMusic) {
                this->stopMusic();
            }
            sound.sound->play();
        }
    } catch (std::invalid_argument const& e) {
        std::cerr << "Warning: AudioSystem::update entity " << entityName << " not found." << std::endl;
    }
}

void AudioSystem::stopAll()
{
    for (Engine::Entity entity : this->getManagedEntities()) {
        auto soundComponent = _entityManager.getComponent<Component::Sound>(entity);

        if (soundComponent.sound->isPlaying()) {
            soundComponent.sound->stop();
        }
    }
}

void AudioSystem::stopMusic()
{
    for (Engine::Entity entity : this->getManagedEntities()) {
        auto musicComponent = _entityManager.getComponent<Component::Sound>(entity);

        if (musicComponent.isMusic && musicComponent.sound->isPlaying()) {
            musicComponent.sound->stop();
        }
    }
}