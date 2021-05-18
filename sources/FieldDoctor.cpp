#include "FieldDoctor.hpp"

using namespace std;
using namespace pandemic;

Player &FieldDoctor::treat(pandemic::City c)
{
    if ((board.get_cubes(c) == 0) || (!Board::is_connected(cur_city, c) && cur_city!=c) )
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (board.is_there_cure(Board::color(c)))
    {
        board.rm_cubes(c);
    }
    else
    {
        board.x_cubes(c);
    }
    return *this;
}