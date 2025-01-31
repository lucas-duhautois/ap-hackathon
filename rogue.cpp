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
#include "rogue.hpp"
#include "Hero.hpp"
#include "item.hpp"
#include "dungeon.hpp"

double randomDouble() {
    static std::random_device rd;  // Génère une graine unique
    static std::mt19937 gen(rd()); // Générateur Mersenne Twister
    static std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribution uniforme

    return dis(gen);
}

board::board(int init_nx, int init_ny, int taille_cases) : nx{init_nx}, ny{init_ny},taille_cases{taille_cases}
  {
  bg.resize(nx * ny, 0);
  };

  int& board::operator()(const int j,const int i){
    return bg[nx*i+j];}




void startGame(board &map, sf::Font font)
{
    static sf::RenderWindow window(sf::VideoMode(map.nx * map.taille_cases, map.ny * map.taille_cases), "rogue");

    std::vector<int> init_pos {10,10};
    Hero player (init_pos, 20, 20, 5, 10, 1, 0);
    while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            {window.close();
            exit(1);}
      
    }
    window.clear(sf::Color::White);
    player.print(window);
    
    window.display();
    
    
    
    }
     
    
  }


int main()
{
  static sf::Font font;
  font.loadFromFile("gamefont.otf");



  const int nx = 100;
  const int ny = 50;
  const int taille = 10;
  board map(nx,ny,taille);

  startGame(map, font);
  return 0;
}