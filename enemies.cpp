#include "enemies.hpp"
#include "Hero.hpp"
#include "rogue.hpp"

EnemyType::EnemyType(int id, std::string nom, const std::string& texturePath, int hp, int damage) : id{id}, nom{nom}, hp{hp}, damage{damage} {
        if (!texture.loadFromFile(texturePath)) {
            std::cerr << "Erreur de chargement : " << texturePath << std::endl;
        }
        dicoEnemies[id] = this;

    }




Enemy::Enemy(EnemyType& type, std::vector<int> coord) : type{type}
{

    hp=type.hp;
    coord = coord;
    sprite = sf::Sprite();
    sprite.setTexture(type.texture);
    sprite.setPosition(20*coord[0], 20*coord[1]);

}

void Enemy::combat(Hero& hero, sf::RenderWindow& window){
        double succes;
        int degats;
        window.clear(sf::Color::Black);
        sf::Text texte;
        texte.setCharacterSize(10); 
        texte.setFillColor(sf::Color::White); 
        texte.setPosition(50, 50);
        texte.setString("un très très méchant " + type.nom + " vous attaque !");
        window.draw(texte);
        window.display();
        while (hp > 0 || hero.hp > 0){
            
            
            if(sf::Keyboard::isKeyPressed(sf::Keyboard::Space)){
                window.clear(sf::Color::Black);
                succes = randomDouble();
                if (succes<0.7){
                    degats = hero.strength + static_cast<Sword*>(hero.weapon)->damage;
                    this->hp = this-> hp-degats;
                    texte.setString("vous frappez et infligez " + std::to_string(degats) + "dégâts");
                }
                else{
                    texte.setString("Vous échouez misérablement à toucher le " + type.nom);
                }
                window.draw(texte);
                window.display();
                sf::sleep(sf::milliseconds(800));
                succes = randomDouble();

                if (succes<0.7){
                
                    degats = type.damage;
                    hero.damage(degats);
                    texte.setString("le " + type.nom + " vous inflige "+ std::to_string(degats) + "dégâts");
                }
                else {
                    texte.setString("le " + type.nom + " vous a raté");
                }
                
                window.draw(texte);
                window.display();
                sf::sleep(sf::milliseconds(800));
            }
            
            
            

        }
        if (hp<=0){
            texte.setString("Bravo ! Vous avez gagné. Le " + type.nom + " est mort.");
        }
        else{
            window.clear(sf::Color::Black);
            texte.setString("Vous êtes mort. Dommage");
            texte.setCharacterSize(80); 
            texte.setPosition(350, 400);
        }
        window.draw(texte);
        window.display();

    }




void Enemy::print(sf::RenderWindow& fen){
    fen.draw(sprite);
}


std::map<int, EnemyType*> EnemyType::dicoEnemies;