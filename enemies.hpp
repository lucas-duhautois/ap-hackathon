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
#include <map>

class Hero;

class EnemyType{
    public:

    static std::map<int, EnemyType*> dicoEnemies;
    int id;
    std::string nom;
    sf::Texture texture;
    int hp;
    int damage;
    float hit_rate;
    
    EnemyType(int id, std::string nom, const std::string& texturePath, int hp, int damage);


    
};


class Enemy{

    EnemyType type;
    int hp;
    sf::Sprite sprite;

    Enemy(EnemyType& type, std::vector<int> coord);

    void combat(Hero& hero, sf::RenderWindow& window);
    void print(sf::RenderWindow& fen);
};
