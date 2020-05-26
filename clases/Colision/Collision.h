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
    std::vector<std::list<Rectangle> *> List;
    Character *player;
    Rectangle player_area;
    Rectangle Fruit_area;
    std::vector<Fruits *> *Fruits_Vec;

public:
    Collision(Character *player);

    void LoadList(std::list<Rectangle> *list1);

    void LoadVector(std::vector<Fruits *> *Fruits);

    bool IsColliding_X();

    bool IsColliding_y();

    bool IsCollidingPlataform();

    bool IsFlying();

    bool IsCollecting();

    bool Is_getting_damage();
};


#endif //RAYLIBTEMPLATE_COLLISION_H
