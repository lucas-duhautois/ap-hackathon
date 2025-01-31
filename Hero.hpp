#pragma once

#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>



class Hero{
    private:
    int Hp_;
    int strength_;
    int xp_;
    int Level_;
    std::vector<int> position_;

    public:
    Hero(std::vector<int> position, int Hp, int strength, int Level, int xp){}

};