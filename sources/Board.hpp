#pragma once

#include<map>
#include<set>
#include<iostream>

#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
    public:

        // Members 
        std::set<Color> disc_cure; // * holds a set of all the cures based on color
        std::set<City> research_station; 
        static std::map<City, std::set<City>> connections; // * key : city | value : set(city)
        std::map<City,int> disease_cubes; // * key : city | value : disease cubes in the city

        // operator [] 
        int &operator[](City c);

        // return true if the board is clean from diseases
        bool is_clean();

        void remove_cures();

        void remove_stations();

        // Output operator - friend for reduse this in arguments
        friend std::ostream &operator<<(std::ostream &os, Board &board);

        // * check if two city are connected based on the map 
        static bool connected ( City &a , City &b );
    };
}

