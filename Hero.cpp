#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>






class Hero{
    protected:
    int Hp_;
    int strength_;
    int xp_;
    int Level_;
    std::vector<int> position_;

    public:
    Hero(std::vector<int> position, int Hp, int strength, int Level, int xp): position_{position}, Hp_{Hp}, strength_{strength},Level_{Level}, xp_{xp}{}

};