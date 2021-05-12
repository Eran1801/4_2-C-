#include "Researcher.hpp"

using namespace pandemic;

const int number_of_cards_for_discover = 5;

Player &Researcher::discover_cure(Color col)
{

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