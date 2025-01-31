#include "item.hpp"

Item::Item (std::array<int, 2> coords) : coords{coords} {}
Potion::Potion (std::array<int, 2> coords, int heal) : Item(coords), heal{heal}, id{1} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}
Sword::Sword (std::array<int, 2> coords, int damage) : Item(coords), damage{damage}, id{2} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}
Xp_bottle::Xp_bottle (std::array<int, 2> coords, int xp) : Item(coords), xp{xp}, id{3} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}
Gold::Gold (std::array<int, 2> coords, int value) : Item(coords), value{value}, id{4} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}
Bow::Bow (std::array<int, 2> coords) : Item(coords), id{5} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}
Armor::Armor (std::array<int, 2> coords) : Item(coords), id{6} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0], coords[1]));
}

void Item::print(sf::RenderWindow &window) {
    window.draw(sprite);
}
void Potion::use(Hero &hero) {
    hero.damage(-heal);
}
void Sword::equip(Hero &hero) {
    
}
void Xp_bottle::use(Hero &hero) {
    hero.gain_xp(xp);
}
void Gold::use (Hero &hero) {
    hero.gain_gold(value);
}

int main () {
    return EXIT_SUCCESS;
}