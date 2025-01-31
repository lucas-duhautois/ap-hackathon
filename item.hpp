#pragma once
#include <vector>
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>
#include "Hero.hpp"

class Item {
    public:
    std::array<int, 2> coords;

    Item() = default;
    Item(std::array<int, 2>);
    ~Item() = default;

    virtual void use(Hero&) = 0;
};

class Potion : public Item {
    public:
    int heal;

    Potion(std::array<int, 2>, int);
    void use(Hero&);
};

class Sword : public Item {
    public:
    int damage;

    Sword(std::array<int, 2>, int);
    void use(Hero&);
};

class Xp_bottle : public Item {
    public:
    int xp;

    Xp_bottle(std::array<int, 2>, int);
    void use(Hero&);
};

class Gold : public Item {
    public:
    void use(Hero&);
}

class Bow : public Item {
    public:
    void use(Hero&);
};

class Armor : public Item {
    public:
    void use(Hero&);
};