#pragma once
#include <vector>
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "Hero.hpp"

class Item {
    public:
    std::array<int, 2> coords;
    sf::Sprite sprite;

    Item() = default;
    Item(std::array<int, 2>);
    ~Item() = default;

    virtual void use(Hero&) = 0;
    void print(sf::RenderWindow&);
};

class Potion : public Item {
    public:
    int heal;
    int id;
    static sf::Texture texture;

    Potion(std::array<int, 2>, int);
    void use(Hero&);
};

class Sword : public Item {
    public:
    int damage;
    int id;
    static sf::Texture texture;


    Sword(std::array<int, 2>, int);
    void equip(Hero&);
};

class Xp_bottle : public Item {
    public:
    int xp;
    int id;
    static sf::Texture texture;

    Xp_bottle(std::array<int, 2>, int);
    void use(Hero&);
};

class Gold : public Item {
    public:
    int value;
    int id;
    static sf::Texture texture;

    Gold(std::array<int, 2>, int);
    void use(Hero&);
};

class Bow : public Item {
    public:
    int id;
    static sf::Texture texture;

    Bow(std::array<int, 2>);
    void use(Hero&);
};

class Armor : public Item {
    public:
    int id;
    static sf::Texture texture;

    Armor(std::array<int, 2>);
    void equip(Hero&);
};