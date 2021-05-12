#include "Board.hpp"
#include "Player.hpp"
#include "Dispatcher.hpp"

using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{

   if (_city == c)
   {
      throw std::__throw_invalid_argument;
   }
   if (_board.research_station.count(_city) == 1)
   {
      _city = c;
      }
   else
   {
      // *call the regular player with this function beacause the Dispatcher not in research_station city
      return Player::fly_direct(c);
   }
   return *this;
}