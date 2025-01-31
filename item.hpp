#pragma once
#include <vector>
#include <iostream>
#include <array>
#include <SFML/Graphics.hpp>

class Hero;

class Item {
    public:
    std::vector<int> coords;
    sf::Sprite sprite;

    Item() = default;
    Item(std::vector<int>);
    ~Item() = default;

    virtual void use(Hero&) = 0;
    void print(sf::RenderWindow&);
    bool add_to_inventory(Hero&);
    bool remove_from_inventory(Hero&);
};

class Potion : public Item {
    public:
    int heal;
    int id;
    static sf::Texture texture;

    Potion(std::vector<int>, int);
    ~Potion() = default;
    void use(Hero&);
};

class Sword : public Item {
    public:
    int damage;
    int id;
    static sf::Texture texture;


    Sword(std::vector<int>, int);
    ~Sword() = default;
    void equip(Hero&);
};

class Xp_bottle : public Item {
    public:
    int xp;
    int id;
    static sf::Texture texture;

    Xp_bottle(std::vector<int>, int);
    ~Xp_bottle() = default;
    void use(Hero&);
};

class Gold : public Item {
    public:
    int value;
    int id;
    static sf::Texture texture;

    Gold(std::vector<int>, int);
    ~Gold() = default;
    void use(Hero&);
};

class Bow : public Item {
    public:
    int id;
    static sf::Texture texture;

    Bow(std::vector<int>);
    ~Bow() = default;
    void use(Hero&);
};

class Armor : public Item {
    public:
    int id;
    static sf::Texture texture;

    Armor(std::vector<int>);
    ~Armor() = default;
    void equip(Hero&);
};