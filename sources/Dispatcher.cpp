#include "Dispatcher.hpp"

using namespace std;
using namespace pandemic;

Player &Dispatcher::fly_direct(City c)
{
    if (cur_city == c)
    {
        throw std::invalid_argument{"Its the same city"};
    }
    if (board.is_research_station(cur_city))
    {
        cur_city = c;
    }
    else if ((bool) cards.count(c))
    {
        cards.erase(c);
        cur_city = c;
    }
    else
    {
        throw invalid_argument{"Theres no match card or research station"};
    }
    return *this;
}