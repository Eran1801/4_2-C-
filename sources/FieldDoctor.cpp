#include "Board.hpp"
#include "Player.hpp"
#include "FieldDoctor.hpp"

using namespace pandemic;

Player &FieldDoctor::treat(City c)
{

    if (pandemic::Board::connections.at(_city).count(c) == 0 && _city != c)
    {
        throw std::__throw_invalid_argument;
    }

    if (_board[c] == 0)
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