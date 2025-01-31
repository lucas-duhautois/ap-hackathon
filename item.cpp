#include "item.hpp"

Item::Item (std::array<int, 2> coords) : coords{coords} {}
Potion::Potion (std::array<int, 2> coords, int heal) : Item(coords), heal{heal} {}
Sword::Sword (std::array<int, 2> coords, int damage) : Item(coords), damage{damage} {}
Xp_bottle::Xp_bottle (std::array<int, 2> coords, int xp) : Item(coords), xp{xp} {}

void Potion::use(Hero &hero) {
    hero.damage(-heal);
}
void Sword::use(Hero &hero) {
    hero.gainstrength(damage);
}
void Xp_bottle::use(Hero &hero) {
    hero.gainxp(xp);
}

int main () {
    return EXIT_SUCCESS;
}