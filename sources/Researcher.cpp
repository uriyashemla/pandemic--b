#include "Researcher.hpp"

using namespace std;
using namespace pandemic;
const int lim = 5;

Player &Researcher::discover_cure(Color c)
{
    if (board.is_there_cure(c))
    {
        return *this;
    }
    int counter = 0;
    for (const auto &col : cards)
    {
        if (Board::color(col) == c)
        {
            counter++;
        }
        if (counter == lim)
        {
            break;
        }
    }
    if (counter == lim)
    {
        counter = 0;
        for (auto iter = cards.begin(); iter != cards.end() || counter < lim; counter++)
        {
            if (Board::color(*iter) == c)
            {
                iter = cards.erase(iter);
            }
            else
            {
                ++iter;
            }
        }
        board.curing(c);
    }
    else
    {
        throw std::invalid_argument{"theres no enough cards"};
    }
    return *this;
}
