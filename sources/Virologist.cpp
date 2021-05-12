#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Virologist.hpp"

using namespace pandemic;

Player &Virologist::treat(City c)
{

    // * if the player not in the same city that was given, throw an Exception
    if (_board[c] == 0)
    {
        throw std::__throw_invalid_argument;
    }

    if (_city != c)
    {
        if (player_card.count(c) == 0)
        {
            throw std::__throw_invalid_argument;
        }
        player_card.erase(c);
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