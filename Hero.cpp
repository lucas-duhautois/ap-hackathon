#include <vector>
#include <iostream>
#include <SFML/Graphics.hpp>
#include "item.hpp"




sf::Texture hero_texture;
sf::Texture inventory_texture;



class Hero{
    public:
    int hp;
    int max_hp;
    int strength;
    int gold;
    int xp;
    int level;

    std::array<Item*, 15> Inventory;
    Item* armor;
    Item* weapon;

    std::vector<int> position;
    sf::Sprite hero_sprite;
    sf::Sprite inventory_sprite;


    Hero(std::vector<int> position, int hp, int max_hp, int strength, int gold, int level, int xp): position{position}, hp{hp}, max_hp{max_hp}, strength{strength}, gold{gold}, level{level}, xp{xp}{

        Inventory = {nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr, nullptr};
        armor = nullptr;
        weapon = nullptr;

        hero_sprite.setTexture(hero_texture);
        hero_sprite.setPosition(20*position[0], 20*position[1]);

        inventory_sprite.setTexture(inventory_texture);
    }

    void print(sf::RenderWindow& window){
        window.draw(hero_sprite);
    }



    void updt(){
        hero_sprite.setPosition(20*position[0], 20*position[1]);
    }

    void print_inventory(sf::RenderWindow& window){
        int x0 = 1200/2 - 125;
        int y0 = 900/2 - 125;

        inventory_sprite.setPosition(x0, y0);
        window.draw(inventory_sprite);

        if (armor != nullptr){
            armor->sprite.setPosition(x0 + 54, y0 + 39);
            armor->sprite.setScale(1.5, 1.5);
        }
        if (weapon != nullptr){
            weapon->sprite.setPosition(x0 + 121, y0 + 39);
            weapon->sprite.setScale(1.5, 1.5);
        }

        for (int i = 0; i < 15; i++){
            if (Inventory[i] != nullptr){
                Inventory[i]->sprite.setPosition(x0 + 25 + 48 * (i%5), y0 + 121 + 48 * (i/3));
                Inventory[i]->sprite.setScale(1.5, 1.5);
            }
        }
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

};




//int main(){
//    if (!hero_texture.loadFromFile("Textures/Hero/rogue_hero.png")){
//        std::cout << "err loading texture" << std::endl;
//    }
//    
//    inventory_texture.loadFromFile("Textures/Inventory.png");
//
//    Hero hero({20, 20}, 1, 1, 1, 1, 1, 1);
//
//    sf::RenderWindow window(sf::VideoMode(1200, 900), "Rogue", sf::Style::Close);
//    while (window.isOpen()) {
//
//        window.clear(sf::Color::White);
//
//        hero.print(window);
//        hero.print_inventory(window);
//
//        window.display();
//
//        sf::Event event;
//        while (window.pollEvent(event)){
//            if (event.type == sf::Event::Closed) {
//                window.close();
//            }
//            else if (event.type == sf::Event::KeyPressed){
//                if(event.key.code == sf::Keyboard::Escape){
//                    window.close();
//                }
//
//                else if (event.key.code == sf::Keyboard::Right){
//                    hero.move_right();
//                }
//                else if (event.key.code == sf::Keyboard::Left){
//                    hero.move_left();
//                }
//                else if (event.key.code == sf::Keyboard::Down){
//                    hero.move_down();
//                }
//                else if (event.key.code == sf::Keyboard::Up){
//                    hero.move_up();
//                }
//                else if (event.key.code == sf::Keyboard::E){
//                    hero.print_inventory(window);
//                }
//            }
//        }
//
//        window.display();
//    }
//
//    return 0;
//}