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

class board{
  public:
  int nx;
  int ny;
  int taille_cases;
  std::vector<int> bg;
  int& operator()(const int,const int);
  board(int, int, int){};
};