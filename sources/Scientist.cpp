#include "Color.hpp"
#include "Board.hpp"
#include "Player.hpp"
#include "Scientist.hpp"

using namespace pandemic;

Player &Scientist::discover_cure(Color col)

{if (_board.research_station.count(_city) == 0){
        throw std::__throw_invalid_argument;
    }

    int counter = 0;
    for(const auto& t : player_card){
        if( t.second == col) {
            counter++;
        }
    }
    if(counter < n){
       throw std::__throw_invalid_argument;
    }

    counter = 1;
    for(auto it = player_card.begin(); it != player_card.end(); counter++){
        if(counter == n) { break; }
        if( (*it).second == col) {
            it = player_card.erase(it);
        }
        else {
            ++it;
        }
    }
    _board.disc_cure.insert(col);
    return *this;
    
}