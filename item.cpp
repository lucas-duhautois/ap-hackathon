#include "item.hpp"
#include "Hero.hpp"

Item::Item (std::vector<int> coords) : coords{coords} {}
Potion::Potion (std::vector<int> coords, int heal) : Item(coords), heal{heal}, id{1} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}
Sword::Sword (std::vector<int> coords, int damage) : Item(coords), damage{damage}, id{2} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}
Xp_bottle::Xp_bottle (std::vector<int> coords, int xp) : Item(coords), xp{xp}, id{3} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}
Gold::Gold (std::vector<int> coords, int value) : Item(coords), value{value}, id{4} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}
Bow::Bow (std::vector<int> coords) : Item(coords), id{5} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}
Armor::Armor (std::vector<int> coords) : Item(coords), id{6} {
    if (!texture.loadFromFile("Textures/")) {
        std::cout << "Render error" << std::endl;
    }
    sprite.setTexture(texture);
    sprite.setPosition(sf::Vector2f(coords[0]*20, coords[1]*20));
    sprite.setScale(sf::Vector2f(19,19));
}

bool Item::add_to_inventory(Hero& hero) {
    for (auto &c : hero.Inventory) {
        if (c == nullptr) {
            c = this;
            return (true);
        }
    }
    return (false);
}
bool Item::remove_from_inventory(Hero& hero) {
    for (auto &c : hero.Inventory) {
        if (c == this) {
            c = nullptr;
            return (true);
        }
    }
    return (false);
}
void Item::print(sf::RenderWindow &window) {
    window.draw(sprite);
}
void Potion::use(Hero &hero) {
    hero.damage(-heal);
    remove_from_inventory(hero);
}
void Sword::equip(Hero &hero) {
    remove_from_inventory(hero);
    hero.weapon->add_to_inventory(hero);
    hero.weapon = this;
}
void Xp_bottle::use(Hero &hero) {
    hero.gain_xp(xp);
    remove_from_inventory(hero);
}
void Gold::use (Hero &hero) {
    hero.gain_gold(value);
    remove_from_inventory(hero);
}
void Armor::equip (Hero &hero) {
    remove_from_inventory(hero);
    hero.armor->add_to_inventory(hero);
    hero.armor = this;
}

int main () {
    return EXIT_SUCCESS;
}