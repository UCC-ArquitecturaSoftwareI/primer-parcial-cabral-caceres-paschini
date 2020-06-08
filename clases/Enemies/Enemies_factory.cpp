//
// Created by martin on 7/6/20.
//

#include "Enemies_factory.h"

void Enemies_factory::Set_Map(std::multimap<std::string, Rectangle> *M) {
    Map = M;
}

std::vector<Entity *> Enemies_factory::Make_Enemies() {
    Rectangle rec{0, 0, 0, 0};
    Vector2 ve{0, 0};
    static std::vector<Entity *> Vec_Enemies;


    rec = Map->find("0")->second;
    ve = {rec.x, rec.y};
    Fat_Bird *Fat;
    Fat = new Fat_Bird("resources/Enemies/Fat_bird_Spritesheet.png", ve);
    Vec_Enemies.push_back(Fat);


    rec = Map->find("1")->second;
    ve = {rec.x, rec.y};
    Plant *Pla;
    Pla = new Plant("resources/Enemies/Plant_Spritesheet.png", ve);
    Vec_Enemies.push_back(Pla);

    rec = Map->find("2")->second;
    ve = {rec.x, rec.y};
    Slime *Sli;
    Sli = new Slime("resources/Enemies/Slime_spritesheet.png", ve);
    Vec_Enemies.push_back(Sli);

    rec = Map->find("3")->second;
    ve = {rec.x, rec.y};
    Turtle *Tur;
    Tur = new Turtle("resources/Enemies/Turtle_spritesheet .png", ve);
    Vec_Enemies.push_back(Tur);

    return Vec_Enemies;

}
