
#include <iostream>
#include "Board.hpp"
#include "Player.hpp"
#include "OperationsExpert.hpp"
#include "City.hpp"
#include "Color.hpp"
#include <set>

using namespace pandemic;

// * returns the number of disease cubes in the city c
int &Board::operator[](City c)
{
    return disease_cubes[c];
}

// * check if the Board is clean from disease
bool Board::is_clean()
{
    // * credit : https://programming-idioms.org/idiom/13/iterate-over-map-keys-and-values/2675/cpp
    for (const auto &map : disease_cubes)
    {
        if (map.second > 0)
        {
            return false;
        }
    }
    return true;
}

void Board::remove_cures()
{
    disc_cure.clear();
}

// * removes all the research station
void Board::remove_stations()
{
    research_station.clear();
}

std::ostream &pandemic::operator<<(std::ostream &os, Board &board)
{

    std::cout << "-----------------Board------------------" << std::endl;
    std::cout << "City"
              << "             disease cube" << std::endl;
    for (const auto &discube : board.disease_cubes)
    {

        std::cout << city_to_string(discube.first) << "               " << discube.second << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "           Color cures : " << std::endl;
    for (const auto &cures : board.disc_cure)
    {
        std::cout << color_to_string(cures) << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;

    std::cout << "          Research station : " << std::endl;
    for (const auto &restai : board.research_station)
    {
        std::cout << city_to_string(restai) << std::endl;
    }

    std::cout << "---------------------------------------------" << std::endl;
    std::cout << std::endl;

    return os;
}

// * check if two city are connected
bool Board::connected(City &a, City &b)
{
    return connections.at(a).count(b) == 1;
}

// * A map of city and her connection
std::map<City, std::set<City>> Board::connections{
    {Algiers, {Madrid, Paris, Istanbul, Cairo}},
    {Atlanta, {Chicago, Miami, Washington}},
    {Baghdad, {Tehran, Istanbul, Cairo, Riyadh, Karachi}},
    {Bangkok, {Kolkata, Chennai, Jakarta, HoChiMinhCity, HongKong}},
    {Beijing, {Shanghai, Seoul}},
    {Bogota, {MexicoCity, Lima, Miami, SaoPaulo, BuenosAires}},
    {BuenosAires, {Bogota, SaoPaulo}},
    {Cairo, {Algiers, Istanbul, Baghdad, Khartoum, Riyadh}},
    {Chennai, {Mumbai, Delhi, Kolkata, Bangkok, Jakarta}},
    {Chicago, {SanFrancisco, LosAngeles, MexicoCity, Atlanta, Montreal}},
    {Delhi, {Tehran, Karachi, Mumbai, Chennai, Kolkata}},
    {Essen, {London, Paris, Milan, StPetersburg}},
    {HoChiMinhCity, {Jakarta, Bangkok, HongKong, Manila}},
    {HongKong, {Bangkok, Kolkata, HoChiMinhCity, Shanghai, Manila, Taipei}},
    {Istanbul, {Milan, Algiers, StPetersburg, Cairo, Baghdad, Moscow}},
    {Jakarta, {Chennai, Bangkok, HoChiMinhCity, Sydney}},
    {Johannesburg, {Kinshasa, Khartoum}},
    {Karachi, {Tehran, Baghdad, Riyadh, Mumbai, Delhi}},
    {Khartoum, {Cairo, Lagos, Kinshasa, Johannesburg}},
    {Kinshasa, {Lagos, Khartoum, Johannesburg}},
    {Kolkata, {Delhi, Chennai, Bangkok, HongKong}},
    {Lagos, {SaoPaulo, Khartoum, Kinshasa}},
    {Lima, {MexicoCity, Bogota, Santiago}},
    {London, {NewYork, Madrid, Essen, Paris}},
    {LosAngeles, {SanFrancisco, Chicago, MexicoCity, Sydney}},
    {Madrid, {London, NewYork, Paris, SaoPaulo, Algiers}},
    {Manila, {Taipei, SanFrancisco, HoChiMinhCity, Sydney, HongKong}},
    {MexicoCity, {LosAngeles, Chicago, Miami, Lima, Bogota}},
    {Miami, {Atlanta, MexicoCity, Washington, Bogota}},
    {Milan, {Essen, Paris, Istanbul}},
    {Montreal, {Chicago, Washington, NewYork}},
    {Moscow, {StPetersburg, Istanbul, Tehran}},
    {Mumbai, {Karachi, Delhi, Chennai}},
    {NewYork, {Montreal, Washington, London, Madrid}},
    {Osaka, {Taipei, Tokyo}},
    {Paris, {Algiers, Essen, Madrid, Milan, London}},
    {Riyadh, {Baghdad, Cairo, Karachi}},
    {SanFrancisco, {LosAngeles, Chicago, Tokyo, Manila}},
    {Santiago, {Lima}},
    {SaoPaulo, {Bogota, BuenosAires, Lagos, Madrid}},
    {Seoul, {Beijing, Shanghai, Tokyo}},
    {Shanghai, {Beijing, HongKong, Taipei, Seoul, Tokyo}},
    {StPetersburg, {Essen, Istanbul, Moscow}},
    {Sydney, {Jakarta, Manila, LosAngeles}},
    {Taipei, {Shanghai, HongKong, Osaka, Manila}},
    {Tehran, {Baghdad, Moscow, Karachi, Delhi}},
    {Tokyo, {Seoul, Shanghai, Osaka, SanFrancisco}},
    {Washington, {Atlanta, NewYork, Montreal, Miami}}};

// int main ( ) { 

//     pandemic::Board board;  // Initialize an empty board (with 0 disease cubes in any city).

//     std::cout << "-----------------PANDEMIC GAME------------------" << std::endl;
//     std::cout << std::endl;

//     std::cout << "-----------------Clean Board------------------" << std::endl;
//     std::cout << std::endl;
//     std::cout << board << std::endl;
// 	board[City::Kinshasa] = 3;      // put 3 yellow disease cubes in Kinshasa.
// 	board[City::Kinshasa] = 2;      // change number of disease cubes in Kinshasa to 2.
// 	board[City::MexicoCity] = 3;    // put 3 yellow disease cubes in MexicoCity
// 	board[City::HoChiMinhCity] = 1; // put 1 red disease cube in HoChiMinhCity
// 	board[City::Chicago] = 1;       // put 1 blue disease cube in Chicago

//     std::cout << "-----------------After puting a disease cube------------------" << std::endl;
//     std::cout << std::endl;

//     std::cout << board << std::endl;

// 	pandemic::OperationsExpert player {board, City::Atlanta};  // initialize an "operations expert" player on the given board, in Atlanta.
// 	player.take_card(City::Johannesburg)
// 	 .take_card(City::Khartoum)
// 	 .take_card(City::SaoPaulo)
// 	 .take_card(City::BuenosAires)
// 	 .take_card(City::HoChiMinhCity);


// 	/* build action */

// 	player.build();  // legal action: you build a research station in Atlanta.
// 		// NOTE: you do not have the Atlanta card, so for other roles this would throw an exception.
// 		//       But for the OperationsExpert it is legal, since he may build a research station without a card.


// 	/* drive action */

// 	player.drive(City::Washington);  // legal action: you drive from Atlanta to a connected city.
// 	player.build();
//     player.drive(City::Montreal);
//     player.build();

//     std::cout << "-----------------After bulding a research station------------------" << std::endl;
//     std::cout << std::endl;

// 	std::cout << board << std::endl;

// }