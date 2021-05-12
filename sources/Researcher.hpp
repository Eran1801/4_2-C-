#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic { 

    class Researcher : public Player { 

        public:
            Researcher(Board &b, City c) : Player(b, c) {}
            Player& discover_cure(Color c) override;
                const std::string role()
        {
            return "Researcher";
        }

    };

}