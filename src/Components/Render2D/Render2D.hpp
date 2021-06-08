/*
** EPITECH PROJECT, 2021
** gameEngine
** File description:
** 02/06/2021 Render2D.hpp.h
*/

#ifndef RENDER2D_HPP
#define RENDER2D_HPP

#include "GameEngine.hpp"
#include "raylib.hpp"
#include <memory>
#include <vector>
#include <unordered_map>

namespace Component
{
    using render2dMapModels = std::unordered_map<std::string, std::shared_ptr<raylib::IRenderable>>;

    class Render2D : public Engine::Component<Render2D> {
      public:
        Render2D(render2dMapModels const &models);
        virtual ~Render2D() = default;

        void add(std::shared_ptr<raylib::IRenderable> model, const std::string &label);
        void remove(const std::string &label);

        void draw();

        bool save(Engine::SaveManager &saver) const override;
        bool load(Engine::SaveManager &saver) override;

      protected:
        std::vector<std::shared_ptr<raylib::IRenderable>> _models;
        std::unordered_map<std::string, std::size_t> _modelIndex;
        std::unordered_map<std::size_t, std::string> _labelIndex;
    };
} // namespace Component

#endif // RENDER2D_HPP