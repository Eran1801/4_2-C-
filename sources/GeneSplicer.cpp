#include "Board.hpp"
#include "Player.hpp"
#include "GeneSplicer.hpp"

using namespace pandemic;

const int number_of_cards_for_discover = 5;

Player &GeneSplicer::discover_cure(Color col)
{
    if (_board.research_station.count(_city) == 0)
    {
        throw std::__throw_invalid_argument;
    }

    if (player_card.size() < number_of_cards_for_discover)
    {
        throw std::__throw_invalid_argument;
    }

    int counter = 1;
        for (auto it = player_card.begin(); it != player_card.end(); counter++)
        {
            if (counter == number_of_cards_for_discover)
            {
                break;
            }
            it = player_card.erase(it);
        }
    _board.disc_cure.insert(col);
    return *this;
}