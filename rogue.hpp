#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <array>
#include <algorithm>
#include <thread>
#include "sys/ioctl.h"
#include "termios.h"
#include "stdio.h"
#include "time.h"
#include "stdlib.h"
#include <SFML/Graphics.hpp>
#include <string>
#include <chrono> 
#include <set>
#include <random>
#include <functional>
#include "Hero.hpp"
#include "dungeon.hpp"
#include "item.hpp"

class board{
  public:
  int nx;
  int ny;
  int taille_cases;
  std::vector<int> bg;
  int& board::operator()(const int j,const int i);
  board::board(int init_nx, int init_ny, int taille_cases){};
};