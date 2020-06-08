//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include <list>
#include "../Character/Character.h"
#include "../Fruits/Fruits.h"
#include <vector>


class Collision {
private:
    std::vector<Rectangle> *Floor_Wall;
    std::vector<Rectangle> *Plataform;
    std::vector<Rectangle> *Traps;
    std::vector<Fruits *> *Fruits_Vec;
    Character *player;
    Rectangle player_area;
    Rectangle Fruit_area;

public:
    Collision(Character *player);

    void Load_Vector(std::vector<Fruits*> *vec);

    void Load_Vector(std::vector<Rectangle> *vec, int Dat);

    bool IsColliding_X();

    bool IsColliding_y();

    bool IsCollidingPlataform();

    bool IsFlying();

    bool IsCollecting();

    bool Is_getting_damage();
};


#endif //RAYLIBTEMPLATE_COLLISION_H
