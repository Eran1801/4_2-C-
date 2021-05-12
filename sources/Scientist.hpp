#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic { 

    class Scientist : public Player { 

        int n ;

        public:
            Scientist(Board &b, City c, int cards) : Player(b, c) , n(cards) {}
            Player& discover_cure(Color) override;
            const std::string role()
        {
            return "Scientist";
        }
    };

}