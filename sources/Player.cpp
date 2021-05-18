#include "Player.hpp"
using namespace std;
const int lim = 5;

namespace pandemic
{
    Player &Player::drive(pandemic::City c)
    {
        if (cur_city == c)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if (Board::is_connected(cur_city, c))
        {
            cur_city = c;
        }
        else
        {
            throw invalid_argument{"Theres no connection between the cities"};
        }
        return *this;
    }

    Player &Player::fly_direct(pandemic::City c)
    {
        if (cur_city == c)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if ((bool)cards.count(c))
        {
            cards.erase(c);
            cur_city = c;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::fly_charter(pandemic::City c)
    {
        if (cur_city == c)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if ((bool)cards.count(cur_city))
        {
            cards.erase(cur_city);
            cur_city = c;
        }
        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::fly_shuttle(pandemic::City c)
    {
        if (cur_city == c)
        {
            throw std::invalid_argument{"Its the same city"};
        }
        if (!board.is_research_station(cur_city) || !board.is_research_station(c))
        {
            throw invalid_argument{"Theres no research stations in both cities"};
        }
        cur_city = c;
        return *this;
    }

    Player &Player::build()
    {
        if (board.is_research_station(cur_city))
        {
            return *this;
        }
        if ((bool)cards.count(cur_city))
        {
            cards.erase(cur_city);
            board.build(cur_city);
        }

        else
        {
            throw invalid_argument{"Theres no match card"};
        }
        return *this;
    }

    Player &Player::discover_cure(Color c)
    {

        if (board.is_there_cure(c))
        {
            return *this;
        }
        if (board.is_research_station(cur_city))
        {
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
        }
        else
        {
            throw std::invalid_argument{"Theres no research station in your city"};
        }
        return *this;
    }

    Player &Player::treat(pandemic::City c)
    {
        if (board.get_cubes(c) == 0)
        {
            throw invalid_argument{"Theres no cubes in the city"};
        }
        if (c != cur_city)
        {
            throw invalid_argument{"The player isn't at the same city"};
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

    Player &Player::take_card(pandemic::City c)
    {
        cards.insert(c);
        return *this;
    }
    Player &Player::remove_cards()
    {
        cards.clear();
        return *this;
    }
}
