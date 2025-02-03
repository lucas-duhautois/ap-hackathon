#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "item.hpp"

class board;



class Hero{
    public:
    int hp;
    int max_hp;
    int strength;
    int gold;
    int xp;
    int level;

    static sf::Texture hero_texture;
    static sf::Texture inventory_texture;

    std::array<Item*, 15> Inventory;
    Item* armor;
    Item* weapon;

    std::vector<int> position;
    sf::Sprite hero_sprite;
    sf::Sprite inventory_sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int gold, int level, int xp);

    void print(sf::RenderWindow& window);
    void updt(int origin, board& map, sf::RenderWindow& window);
    void print_inventory(sf::RenderWindow& window);

    static void load_hero_texture(const std::string& path);
    static void load_inventory_texture(const std::string& path);

    void kill();
    void damage(int amount);
    void gain_xp(int amount);
    void gain_strength(int amount);
    void gain_gold(int amount);
    void move_left(board& map, sf::RenderWindow& window);
    void move_right(board& map, sf::RenderWindow& window);
    void move_down(board& map, sf::RenderWindow& window);
    void move_up(board& map, sf::RenderWindow& window);
};