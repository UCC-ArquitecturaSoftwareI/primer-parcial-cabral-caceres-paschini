//
// Created by martin on 7/6/20.
//

#include "Enemies_factory.h"

void Enemies_factory::Set_Map(std::multimap<std::string, Rectangle> *M) {
    Map = M;
}

std::vector<Enemies *> Enemies_factory::Make_Enemies() {
    Rectangle rec{0, 0, 0, 0};
    Vector2 ve{0, 0};
    std::vector<Enemies *> Vec_Enemies;
    int Counter;

    auto Finder = Map->find("0");

    while (Finder != Map->end()) {
        rec = Finder->second;
        ve = {rec.x, rec.y};
        Fat_Bird *Fat;
        Fat = new Fat_Bird("resources/Enemies/Fat_bird_Spritesheet.png", ve);
        Map->erase(Finder);
        Finder = Map->find("0");
        Vec_Enemies.push_back(Fat);
    }

    Finder = Map->find("1");
    while (Finder != Map->end()) {
        rec = Map->find("1")->second;
        ve = {rec.x, rec.y};
        Plant *Pla;
        Pla = new Plant("resources/Enemies/Plant_Spritesheet.png", ve);
        Map->erase(Finder);
        Finder = Map->find("1");
        Vec_Enemies.push_back(Pla);
    }

    Finder = Map->find("2");
    while (Finder != Map->end()) {
        rec = Map->find("2")->second;
        ve = {rec.x, rec.y};
        Slime *Sli;
        Sli = new Slime("resources/Enemies/Slime_spritesheet.png", ve);
        Map->erase(Finder);
        Finder = Map->find("1");
        Vec_Enemies.push_back(Sli);
    }

    Finder = Map->find("3");
    while (Finder != Map->end()) {
        rec = Map->find("3")->second;
        ve = {rec.x, rec.y};
        Turtle *Tur;
        Tur = new Turtle("resources/Enemies/Turtle_spritesheet .png", ve);
        Map->erase(Finder);
        Finder = Map->find("3");
        Vec_Enemies.push_back(Tur);
    }

    return Vec_Enemies;

}
