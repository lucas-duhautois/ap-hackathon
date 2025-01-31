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





class board
{public:
  int nx;
  int ny;
  int taille_cases;
  std::vector<int> bg;


  board(int init_nx, int init_ny, int taille_cases) : nx{init_nx}, ny{init_ny},taille_cases{taille_cases}
  {
  bg.resize(nx * ny, 0);
  }

  int& operator()(const int j,const int i){
    return bg[nx*i+j];

}



};



void startGame(board &map)
{
    sf::RenderWindow window(sf::VideoMode(map.nx * map.taille_cases, map.ny * map.taille_cases), "rogue");
    while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            {window.close();
            exit(1);}
      
    }
  
    
    
    
    }
     
    
  }


int main()
{
  const int nx = 100;
  const int ny = 50;
  const int taille = 10;
  board map(nx,ny,taille);


  startGame(map);
  return 0;
}