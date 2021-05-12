#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic
{

    class OperationsExpert : public Player
    {

    public:
        // * When building an object from a particular class, one must first build an object from the authorized class
        OperationsExpert(Board &b, City c) : Player(b, c) {}
        Player &build() override;
        const std::string role()
        {
            return "OperationsExpert";
        }
    };

}