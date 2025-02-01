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

double randomDouble();
class Item;
class Enemy;

class board{
  public:
  int nx;
  int ny;
  int taille_cases;
  std::vector<int> bg;
  std::map<std::vector<int>, Item*> dico_Item;
  std::map<std::vector<int>, Enemy*> dico_Enemy;

  int& operator()(const int,const int);
  int& operator()(std::vector<int>);
  board(int, int, int);
  void draw(sf::RenderWindow&);
};