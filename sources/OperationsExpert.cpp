#include "OperationsExpert.hpp"

using namespace std;
using namespace pandemic;

Player &OperationsExpert::build()
{
    if (!board.is_research_station(cur_city))
    {
        board.build(cur_city);
    }
    return *this;
}