#pragma once
#include <map>
#include <set>
#include <iostream>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{

    class Board
    {
        std::map<City, int> diseas;
        std::set<City> stations;
        std::set<Color> already_cured;

    public:
        Board() {}
        bool is_clean();
        static bool is_connected(City &c1, City &c2);
        void build(City c);
        bool is_research_station(City c);
        void curing(Color c);
        bool is_there_cure(Color c);
        int get_cubes(City c);
        void x_cubes(City c);
        void rm_cubes(City c);
        static Color color(City c);
        int &operator[](City c);
        friend std::ostream &operator<<(std::ostream &os, const Board &board);
        void remove_cures();
        void remove_stations();
        ~Board(){}
    };

}