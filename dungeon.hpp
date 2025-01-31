#pragma once
#include <iostream>
#include <vector>
#include <array>
#include <SFML/Graphics.hpp>
#include "item.hpp"
#include "rogue.hpp"

class room {
public:
std::vector<int> position;
int Lx;
int Ly;
room(int init_Lx ,int init_Ly, std::vector<int>init_p, board &map);

};

class tile {
public:
std::vector<int> position;

int direction = 0;

tile(std::vector<int>init_p, board &map,int init_direction);

};