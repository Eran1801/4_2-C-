#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic { 

    class GeneSplicer : public Player { 

        public:
            GeneSplicer(Board &b, City c) : Player(b, c) {}
            Player& discover_cure(Color) override;
            const std::string role()
        {
            return "GeneSplicer";
        }

        int cards () override {
            return player_card.size();
        }
    

    };

}