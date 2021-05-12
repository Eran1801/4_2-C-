#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{

    class Virologist : public Player
    {

    public:
        Virologist(Board &b, City c) : Player(b, c) {}
        Player &treat(City) override;
        const std::string role()
        {
            return "Virologist";
        }
    };

}