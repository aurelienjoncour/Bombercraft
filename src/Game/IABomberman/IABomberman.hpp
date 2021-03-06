/*
** EPITECH PROJECT, 2021
** indiestudio
** File description:
** IABomberman
*/

#ifndef IABOMBERMAN_HPP
#define IABOMBERMAN_HPP

#include <iostream>
#include <ctime>
#include "IACore.hpp"
#include "Game/CoreData/CoreData.hpp"
#include "../../ConfigFile/IConfigFile.hpp"

namespace GameModule
{
    enum class BombermanAction
    {
        ACTION_NONE = 0,
        ACTION_TRIGGER_BOMBE,
    };

    class IABomberman : public IA::IACore<TileType, BombermanAction> {
      public:
        IABomberman(std::pair<size_t, size_t> pos = {0, 0}, std::vector<std::vector<TileType>> env = {});
        ~IABomberman() = default;

        void setRandomMove(size_t randomness);
        void setRandomBomb(size_t randomness);

        void setRange(size_t range);
        IA::Movement getIAMovement();
        void setEnemyPos(std::vector<std::pair<size_t, size_t>> enemy);
        void setIAEnv(std::vector<std::vector<TileType>> env);
        raylib::MyVector3 getOrientation() const;

      private:
        // SETTINGS
        void IASettings();

        // To set in IACore
        bool actionPutBomber(std::pair<size_t, size_t> pos, std::vector<std::vector<TileType>> env);
        void movementPrediction(
            std::pair<size_t, size_t> pos, std::vector<std::vector<TileType>> env, std::queue<IA::Movement> &list);

        // Internal function
        bool findSecurePlace(
            std::pair<size_t, size_t> pos, std::vector<std::vector<TileType>> env, std::queue<IA::Movement> &list);
        std::vector<std::vector<TileType>> getMapWithExposionEffect(
            std::vector<std::vector<TileType>> env, const std::pair<size_t, size_t> &pos, size_t range) const;
        void randomMove(
            const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env, std::queue<IA::Movement> &list);
        bool offensiveMove(
            const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env, std::queue<IA::Movement> &list);
        bool isRandomMove() const;
        void attackBusy(const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env, std::queue<IA::Movement> &list);

        // TOOLS
        bool isStuck() const;
        bool isRunnable(TileType type) const;
        bool isSecurePlace(TileType type) const;
        void clearQueue(std::queue<IA::Movement> &list);
        bool isEnemy(const std::pair<size_t, size_t> &pos) const;
        bool isCorrectMove(const std::pair<size_t, size_t> &) const;
        bool isCorrectBomb(const std::pair<size_t, size_t> &pos) const;
        void loadPath(const std::vector<std::vector<int>> &tab, std::pair<size_t, size_t> end, std::queue<IA::Movement> &list) const;
        std::vector<std::vector<int>> getCostArray(const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env) const;
        std::pair<size_t, size_t> getCostLessSafeMove(const std::vector<std::vector<int>> &tab, const std::vector<std::vector<TileType>> &env, bool &stat) const;
        std::vector<std::vector<int>> findEnemy(const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env) const;
        std::vector<std::pair<size_t, size_t>> getAvailableTile(const std::pair<size_t, size_t> &pos, const std::vector<std::vector<TileType>> &env) const;
        std::pair<size_t, size_t> getNextPos(IA::Movement move) const;
        raylib::MyVector3 findOrientation(const std::pair<size_t, size_t> &pos, const std::pair<size_t, size_t> &bomb) const;
        
        private:
            size_t _range;
            int _defaultValue;
            size_t _randomMove;
            size_t _randomBomb;
            raylib::MyVector3 _orentation;
    };
} // namespace GameModule

#endif