#include "Color.hpp"
#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include <iostream>
#include <fstream>
#include <set>

const int number_of_cards_for_discover = 5;

using namespace pandemic;

/* Moving from the current city to a only neighbor city */
Player &Player::drive(City c)
{
    if (_city == c || !pandemic::Board::connected(_city, c))
    {
        throw std::invalid_argument("g");
    }
    _city = c;
    arrive();
    return *this;
}

/* Fly from the current city to a city that you have the card of it, and throw the the dest city card*/
Player &Player::fly_direct(City c)
{
    if (_city == c || player_card.count(c) == 0)
    {
        throw std::__throw_invalid_argument;
    }

    _city = c;
    player_card.erase(c);
    arrive();
    return *this;
}

/* Fly from the current city to any city, and throw the the current city card */
Player &Player::fly_charter(City c)
{
    if (_city == c)
    {
        throw std::__throw_invalid_argument;
    }

    if (player_card.count(_city) == 0)
    {
        throw std::__throw_invalid_argument;
    }

    player_card.erase(_city);
    _city = c;
    arrive();
    return *this;
}

/* if there is a research station you can fly but dest also a research station */
Player &Player::fly_shuttle(City c)
{
    if (_city != c)
    {
        if (_board.research_station.count(_city) == 1 && _board.research_station.count(c) == 1)
        {
            _city = c;
            arrive();
            return *this;
        }

        throw std::__throw_invalid_argument;
    }
    
        throw std::__throw_invalid_argument;

}

/* Build a research station, throw the current city card */
Player &Player::build()
{
    if (player_card.count(_city) == 1)
    {
        if (_board.research_station.count(_city) == 0)
        {
            _board.research_station.insert(_city);
            player_card.erase(_city);
            return *this;
        }
        return *this;
    }
    throw std::__throw_invalid_argument;
}

Player &Player::discover_cure(Color col)
{

    if (_board.research_station.count(_city) == 0)
    {
        throw std::__throw_invalid_argument;
    }

    int counter = 0;
    for (const auto &t : player_card)
    {
        if (t.second == col)
        {
            counter++;
        }
    }
    if (counter < number_of_cards_for_discover)
    {
        throw std::__throw_invalid_argument;
    }

    counter = 1;
    for (auto it = player_card.begin(); it != player_card.end(); counter++)
    {
        if (counter == number_of_cards_for_discover)
        {
            break;
        }
        if ((*it).second == col)
        {
            it = player_card.erase(it);
        }
        else
        {
            ++it;
        }
    }
    _board.disc_cure.insert(col);
    return *this;
}

Player &Player::treat(City c)
{
    // * if the player not in the same city that was given, throw an Exception
    if (_board[c] == 0 || _city != c)
    {
        throw std::__throw_invalid_argument;
    }

    Color col = _city_color.at(c);
    if (_board.disc_cure.count(col) == 1)
    {
        _board[c] = 0;
    }
    else
    {
        _board[c]--;
    }
    return *this;
}

Player &Player::take_card(City city)
{

    player_card.insert({city, _city_color.at(city)});
    return *this;
}

Player &Player::remove_cards()
{
    player_card.clear();
    return *this;
}