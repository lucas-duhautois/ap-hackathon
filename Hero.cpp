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

    std::vector<Item*> Inventory;
    Item* armor;
    Item* weapon;

    std::vector<int> position;
    sf::Sprite hero_sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int gold, int level, int xp): position{position}, hp{hp}, max_hp{max_hp}, strength{strength}, gold{gold}, level{level}, xp{xp}{

        Inventory = std::vector<Item*>(15);

        sf::Texture texture;
        texture.loadFromFile("Textures/rogue_hero.png");
        hero_sprite.setTexture(texture);
    }

    void print(sf::RenderWindow& window){
        window.draw(hero_sprite);
    }



    void updt(){
        hero_sprite.setPosition(20*position[0], 20*position[1]);
    }

    void print_inventory(){
        int x0 = 0;
        int y0 = 0;
        
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
        this->updt();
    }

    void move_right(){
        position[0]++;
        this->updt();
    }

    void move_down(){
        position[1]++;
        this->updt();
    }

    void move_up(){
        position[1]--;
        this->updt();
    }

    void equip_armor(int location){
        Item* former_armor = armor;
        armor = Inventory[location];
        Inventory[location] = former_armor;
    }

    void equip_weapon(int location){
        Item* former_weapon = weapon;
        weapon = Inventory[location];
        Inventory[location] = former_weapon;
    }

};