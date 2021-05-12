#include "City.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"

using namespace pandemic;

Player &OperationsExpert::build()
{
    _board.research_station.insert(_city);
    return *this;
}