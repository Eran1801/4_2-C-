#include "Board.hpp"
#include "Player.hpp"
#include "Color.hpp"
#include "Medic.hpp"

using namespace pandemic;

Player &Medic::treat(City c)
{

    if (_city != c) {
        throw std::__throw_invalid_argument;
    }
    if (_board[c] == 0) {
        throw std::__throw_invalid_argument;
    }

    _board[c] = 0;
    return *this;
}

void Medic::arrive()
{
    Color col = _city_color.at(_city);
    if (_board.disc_cure.count(col) == 1)
    {
        _board[_city] = 0;
    }
}