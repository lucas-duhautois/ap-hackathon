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
    int level;

    std::vector<int> Inventory;
    std::vector<int> Armor;

    std::vector<int> position;
    sf::Sprite sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int gold, int level, int xp): position{position}, hp{hp}, max_hp{max_hp}, strength{strength}, gold{gold}, level{level}, xp{xp}{

        Inventory = std::vector<int>(15, 0);

        sf::Texture texture;
        texture.loadFromFile("Textures/rogue_hero.png");
        sprite.setTexture(texture);
    }

    void kill(){}

    void damage(int amount){
        hp += amount;
        if (hp >= max_hp){
            hp = max_hp;
        }

        if (hp <= 0){
            this->kill();
        }
    }

    void gain_xp(int amount){
        xp += amount;
        int max_xp = 10 * level;
        while (xp <= max_xp){
            xp -= max_xp;
            level ++;
            strength += level/3 + 1;
            max_hp += level * 3;
            max_xp = 10 * level;
        }
    }

    void gain_strength(int amount){
        strength += amount;
        if (strength < 0){
            strength = 0;
        }
    }

    void gain_gold(int amount){
        gold += amount;
    }

    void move_left(){
        position[0]--;
    }

    void move_right(){
        position[0]++;
    }

    void move_down(){
        position[1]++;
    }

    void move_up(){
        position[1]--;
    }

};