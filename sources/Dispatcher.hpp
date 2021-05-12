#pragma once

#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"

namespace pandemic { 

    class Dispatcher : public Player { 

        public:
            Dispatcher(Board &b, City c) : Player(b, c) {}
            Player& fly_direct(City) override;
            const std::string role()
        {
            return "Dispatcher";
        }


    };

}