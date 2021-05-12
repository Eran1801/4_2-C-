#pragma once

#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <string>

namespace pandemic
{

    class Player
    {

    protected:
        City _city;
        Board &_board;
        std::map<City, Color> player_card; 

    public:
        // Constructor
        Player(Board &board, City &city) : _board(board), _city(city) {}

        // function

        /* Moving from the current city to a only neighbor city */
        Player &drive(City c);

        /* Fly from the current city to a city that you have the card of it, and throw the the dest city card*/
        virtual Player &fly_direct(City c);

        /* Fly from the current city to any city, and throw the the current city card */
        Player &fly_charter(City c);

        /* if there is a research station you can fly but dest also a research station */
        Player &fly_shuttle(City c);

        /* Build a research station, throw the current city card */
        virtual Player &build();

        virtual Player &discover_cure(Color col);

        virtual Player &treat(City c);

        /* Return the role of the player */
        const std::string role(){
            return "Player";
        }

        Player &remove_cards();

        Player &take_card(City city);

        virtual void arrive(){};

        virtual int cards () {
            return player_card.size();
        }

    };
}