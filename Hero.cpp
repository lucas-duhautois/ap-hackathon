#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>






class Hero{
    protected:
    int hp_;
    int max_hp_;
    int strength_;
    int xp_;
    int Level_;
    std::vector<int> position_;

    public:
    Hero(std::vector<int> position, int hp, int max_hp, int strength, int Level, int xp): position_{position}, hp_{hp}, max_hp_{max_hp}, strength_{strength},Level_{Level}, xp_{xp}{}

    void kill(){}

    void damage(int amount){
        hp_ += amount;
        if (hp_ >= max_hp_){
            hp_ = max_hp_;
        }

        if (hp_ <= 0){
            this->kill();
        }
    }

    void gain_xp(int amount){
        xp_ += amount;
        int max_xp = 10 * Level_;
        if (xp_ <= max_xp){
            xp_ = xp_ / max_xp;
        }

    }

};