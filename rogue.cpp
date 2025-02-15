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
#include "enemies.hpp"

double randomDouble() {
    static std::random_device rd;  // Génère une graine unique
    static std::mt19937 gen(rd()); // Générateur Mersenne Twister
    static std::uniform_real_distribution<double> dis(0.0, 1.0); // Distribution uniforme

    return dis(gen);
}

board::board(int init_nx, int init_ny, int taille_cases) : nx{init_nx}, ny{init_ny}, taille_cases{taille_cases} {
    bg.resize(nx * ny, 0);
}

int& board::operator()(const int j, const int i) {
    return bg[nx * i + j];
}


int& board::operator()(std::vector<int> pos) {
    return bg[nx *pos[1]  + pos[0]];
}

void board::draw(sf::RenderWindow& window) {
    for (int y = 0; y < ny; ++y) {
        for (int x = 0; x < nx; ++x) {
            int cellValue = this->operator()(x, y);

            sf::RectangleShape rect(sf::Vector2f(taille_cases, taille_cases));
            rect.setPosition(x * taille_cases, y * taille_cases);

            switch (cellValue) {
                case 0: // E.g. wall
                    rect.setFillColor(sf::Color(10, 10, 10)); // dark gray
                    break;
                case 1: // E.g. floor
                    rect.setFillColor(sf::Color(100, 100, 100)); // lighter gray
                    break;
                case 2: // Another tile type
                    rect.setFillColor(sf::Color(50, 50, 50));
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

void startGame(board &map, sf::Font font) {
    auto start_up = std::chrono::high_resolution_clock::now();
    auto start_down = std::chrono::high_resolution_clock::now();
    auto start_left = std::chrono::high_resolution_clock::now();
    auto start_right = std::chrono::high_resolution_clock::now();
    bool inventory_opened = false;
    static sf::RenderWindow window(sf::VideoMode(map.nx * map.taille_cases, map.ny * map.taille_cases), "rogue");
    std::time_t seed;
    srand(seed);

    std::vector<int> init_room {rand()%(map.nx-20),rand()%(map.ny-20)};
    room Piece(7, 7, init_room, map);
    
    std::vector<int> init_pos {init_room[0] + 3, init_room[1] + 3};
    Hero player(init_pos, 20, 20, 5, 10, 1, 0);

    Sword test({10, 10}, 4);
    test.add_to_inventory(player);
    window.display();
    test.equip(player);


    Enemy gob1(*EnemyType::dicoEnemies[201], std::vector<int> {init_pos[0]-2, init_pos[1]-2});

    map.dico_Enemy[gob1.coord] = &gob1;

    map(gob1.coord) = 201;

    while (window.isOpen()) {

        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
                exit(1);
            } else if (event.type == sf::Event::KeyPressed) {
                auto stop = std::chrono::high_resolution_clock::now();
                auto cooldown_left = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start_left);
                auto cooldown_right = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start_right);
                auto cooldown_up = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start_up);
                auto cooldown_down = std::chrono::duration_cast<std::chrono::milliseconds>(stop - start_down);

                if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                    exit(1);
                } else if (event.key.code == sf::Keyboard::Right && map(player.position[0] + 1, player.position[1]) != 0 && cooldown_right.count() > 100) {
                    player.move_right(map, window);
                    start_right = std::chrono::high_resolution_clock::now();
                } else if (event.key.code == sf::Keyboard::Left && map(player.position[0] - 1, player.position[1]) != 0 && cooldown_left.count() > 100) {
                    player.move_left(map, window);
                    start_left = std::chrono::high_resolution_clock::now();
                } else if (event.key.code == sf::Keyboard::Down && map(player.position[0], player.position[1] + 1) != 0 && cooldown_down.count() > 100) {
                    player.move_down(map, window);
                    start_down = std::chrono::high_resolution_clock::now();
                } else if (event.key.code == sf::Keyboard::Up && map(player.position[0], player.position[1] - 1) != 0 && cooldown_up.count() > 100) {
                    player.move_up(map, window);
                    start_up = std::chrono::high_resolution_clock::now();
                } else if (event.key.code == sf::Keyboard::E) {
                    inventory_opened = !inventory_opened;
                }
            }
        }

        window.clear(sf::Color::White);

        map.draw(window);
        player.print(window);
        gob1.print(window);
        if (inventory_opened) {
            player.print_inventory(window);
        }

        window.display();
    }
}

int main() {
    Hero::load_hero_texture("Textures/Hero/rogue_hero.png");
    Hero::load_inventory_texture("Textures/Inventory.png");

    Potion::loadTexture("Textures/Items/potion.png");
    Sword::loadTexture("Textures/Items/sword.png");
    Xp_bottle::loadTexture("Textures/Items/xp_bottle.png");
    Gold::loadTexture("Textures/Items/gold.png");
    EnemyType gobelin(201, "gobelin", "Textures/enemies/gobelin.png", 10, 4);
    EnemyType slime(211, "slime", "Textures/enemies/slime.png", 15, 2);
    // Armor::loadTexture("Textures/Items/armor.png");

    static sf::Font font;
    font.loadFromFile("gamefont.otf");

    const int nx = 60;
    const int ny = 45;
    const int taille = 20;
    board map(nx, ny, taille);

    startGame(map, font);
    return 0;
}