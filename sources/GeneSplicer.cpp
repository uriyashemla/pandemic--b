#include "GeneSplicer.hpp"

using namespace std;
using namespace pandemic;
const int lim = 5;

Player &GeneSplicer::discover_cure(Color c)
{
    if (!board.is_research_station(cur_city))
    {
        throw std::invalid_argument{"Theres no research station in your city"};
    }
    if (cards.size() >= lim)
    {
        int counter = 0;
        for (auto iter = cards.begin(); iter != cards.end() || counter < lim; counter++)
        {
            iter = cards.erase(iter);
        }
        board.curing(c);
    }
    else
    {
        throw std::invalid_argument{"theres no enough cards"};
    }
    return *this;
}