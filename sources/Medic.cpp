#include "Medic.hpp"
#include "Board.hpp"

using namespace std;
using namespace pandemic;

Player &Medic::treat(City c)
{
    if (board.get_cubes(c) == 0)
    {
        throw invalid_argument{"Theres no cubes in the city"};
    }
    if (c != cur_city)
    {
        throw invalid_argument{"The player isn't at the same city"};
    }
    board.rm_cubes(c);
    return *this;
}

Player &Medic::drive(pandemic::City c)
{
    if (cur_city == c)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (Board::is_connected(cur_city, c))
    {
        cur_city = c;
        if (board.is_there_cure(Board::color(c)))
        {
            board.rm_cubes(c);
        }
    }
    else
    {
        throw invalid_argument{"Theres no connection between the cities"};
    }
    return *this;
}

Player &Medic::fly_direct(pandemic::City c)
{
    if (cur_city == c)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if ((bool)cards.count(c))
    {
        cards.erase(c);
        cur_city = c;
        if (board.is_there_cure(Board::color(c)))
        {
            board.rm_cubes(c);
        }
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
    return *this;
}

Player &Medic::fly_charter(pandemic::City c)
{
    if (cur_city == c)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if ((bool)cards.count(cur_city))
    {
        cards.erase(cur_city);
        cur_city = c;
        if (board.is_there_cure(Board::color(c)))
        {
            board.rm_cubes(c);
        }
    }
    else
    {
        throw invalid_argument{"Theres no match card"};
    }
    return *this;
}

Player &Medic::fly_shuttle(pandemic::City c)
{
    if (cur_city == c)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (board.is_research_station(c) && board.is_research_station(cur_city))
    {
        cur_city = c;
        if (board.is_there_cure(Board::color(c)))
        {
            board.rm_cubes(c);
        }
    }
    else
    {
        throw invalid_argument{"Theres no research stations in both cities"};
    }
    return *this;
}