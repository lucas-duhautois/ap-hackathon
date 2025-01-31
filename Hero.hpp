#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>



class Hero{
    public:
    int Hp;
    int max_hp;
    int strength;
    int xp;
    int Level;
    std::vector<int> position;


    Hero(std::vector<int> position, int hp, int maxhp, int strength, int Level, int xp){}

    void kill(){}
    void damage(int amount){}
    void gainxp(int amount){}
    void gainstrength(int amount){}
    void move_left(){}
    void move_right(){}
    void move_down(){}
    void move_up(){}
};