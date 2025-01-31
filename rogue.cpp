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

void board::draw(sf::RenderWindow&  window){
 for (int y = 0; y < ny; ++y)
    {
        for (int x = 0; x < nx; ++x)
        {
    
            int cellValue = this->operator()(x, y);

            sf::RectangleShape rect(sf::Vector2f(taille_cases, taille_cases));
            rect.setPosition(x * taille_cases, y * taille_cases);

            switch(cellValue)
            {
                case 0: // E.g. empty/floor
                    rect.setFillColor(sf::Color(50, 50, 50)); // dark gray
                    break;
                case 1: // E.g. wall
                    rect.setFillColor(sf::Color(100, 100, 100)); // lighter gray
                    break;
                case 2: // Another tile type
                    rect.setFillColor(sf::Color::Blue);
                    break;
                default:
                    rect.setFillColor(sf::Color::Magenta); // unknown
                    break;
            }

            // Draw the cell
            window.draw(rect);
        }
    }

}



void startGame(board &map, sf::Font font)
{   std::srand(static_cast<unsigned>(std::time(nullptr)));
    bool inventory_opened = false;
    static sf::RenderWindow window(sf::VideoMode(map.nx * map.taille_cases, map.ny * map.taille_cases), "rogue");
    room Piece(10,10,std::vector<int> {0,0},map);

    std::vector<int> init_pos {10,10};
    Hero player(init_pos, 20, 20, 5, 10, 1, 0);
    Sword test({10, 10}, 4);
    test.add_to_inventory(player);
    map.draw(window);
    window.display();
    while (window.isOpen())
  {
    sf::Event event;
    while (window.pollEvent(event)){
           if (event.type == sf::Event::Closed) {
               window.close();
               exit(1);
           }
           else if (event.type == sf::Event::KeyPressed){
               if(event.key.code == sf::Keyboard::Escape){
                   window.close();
                   exit(1);
               }

               else if (event.key.code == sf::Keyboard::Right){
                   player.move_right();
               }
               else if (event.key.code == sf::Keyboard::Left){
                   player.move_left();
               }
               else if (event.key.code == sf::Keyboard::Down){
                   player.move_down();
               }
               else if (event.key.code == sf::Keyboard::Up){
                   player.move_up();
               }
               else if (event.key.code == sf::Keyboard::E){
                 inventory_opened = !inventory_opened;
              }
           }
      
    }
    //window.clear(sf::Color::White);
    player.print(window);
    if (inventory_opened){
      player.print_inventory(window);
    }
    
    window.display();
    
    
    
    }
     
    
  }


int main()
{

  Hero::load_hero_texture("Textures/Hero/rogue_hero.png");
  Hero::load_inventory_texture("Textures/Inventory.png");

  Potion::loadTexture("Textures/Items/potion.png");
  Sword::loadTexture("Textures/Items/sword.png");
  Xp_bottle::loadTexture("Textures/Items/xp_bottle.png");
  Gold::loadTexture("Textures/Items/gold.png");
  //Armor::loadTexture("Textures/Items/armor.png");

  static sf::Font font;
  font.loadFromFile("gamefont.otf");



  const int nx = 80;
  const int ny = 60;
  const int taille = 10;
  board map(nx,ny,taille);

  startGame(map, font);
  return 0;
}