#include "Virologist.hpp"

using namespace std;
using namespace pandemic;

Player &Virologist::treat(City c)
{
    if (board.get_cubes(c) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (! (bool) cards.count(c) && cur_city!=c)
    {
        throw invalid_argument{"Theres no match card"};
    }
    if (board.is_there_cure(Board::color(c)))
    {
        board.rm_cubes(c);
        cards.erase(c);
    }
    else
    {
        board.x_cubes(c);
        cards.erase(c);
    }
    return *this;
}