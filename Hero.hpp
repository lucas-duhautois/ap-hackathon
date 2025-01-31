#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>



class Hero{
    public:
    int hp;
    int max_hp;
    int strength;
    int gold;
    int xp;
    int Level;

    std::vector<int> Inventory;
    std::vector<int> Armor;

    std::vector<int> position;
    sf::Sprite sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int Level, int xp){}

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