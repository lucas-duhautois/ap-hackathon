#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "item.hpp"



class Hero{
    public:
    int hp;
    int max_hp;
    int strength;
    int gold;
    int xp;
    int level;

    std::array<Item*, 15> Inventory;
    Item* armor;
    Item* weapon;

    std::vector<int> position;
    sf::Sprite hero_sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int Level, int xp){}

    void print(sf::RenderWindow& window){}
    void updt(){}
    void print_inventory(){}


    void kill(){}
    void damage(int amount){}
    void gain_xp(int amount){}
    void gain_strength(int amount){}
    void gain_gold(int amount){}
    void move_left(){}
    void move_right(){}
    void move_down(){}
    void move_up(){}
};