#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>






class Hero{
    public:
    int hp;
    int max_hp;
    int strength;
    int xp;
    int Level;
    std::vector<int> position;


    Hero(std::vector<int> position, int hp, int maxhp, int strength, int Level, int xp): position{position}, hp{hp}, max_hp{max_hp}, strength{strength},Level{Level}, xp{xp}{}

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

    void gainxp(int amount){
        xp += amount;
        int max_xp = 10 * Level;
        if (xp <= max_xp){
            xp = xp % max_xp;
            Level ++;
        }
    }

    void gainstrength(int amount){
        strength ++;
        if (strength < 0){
            strength = 0;
        }
    }



};