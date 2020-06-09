//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include "../Character/Character.h"
#include "../Enemies/Enemies.h"
#include "../Fruits/Fruits.h"
#include <vector>


class Collision {
private:
    std::vector<Rectangle> *Floor_Wall;
    std::vector<Rectangle> *Plataform;
    std::vector<Rectangle> *Traps;
    std::vector<Fruits *> *Fruits_Vec;
    Rectangle Ent_Rec;
    Rectangle Enemie_Rec;
    Rectangle Fruit_area;

public:
    Collision();

    void Load_Vector(std::vector<Fruits*> *vec);

    void Load_Vector(std::vector<Rectangle> *vec, int Dat);

    bool IsColliding_X(Enemies *Ent);

    bool IsColliding_X(Character *Ent);

    bool IsColliding_y(Enemies *Ent);

    bool IsColliding_y(Character *Ent);

    bool IsCollidingPlataform(Character *Ent);

    bool IsFlying(Character *Ent);

    bool IsCollecting(Character *Ent);

    bool Dmg(Character *Ent);

    bool Dmg(Character *Ent,Enemies *Ene);
};


#endif //RAYLIBTEMPLATE_COLLISION_H
