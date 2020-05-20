//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include <list>
#include "../Character/Character.h"
#include <vector>


class Collision {
private:
    std::vector<std::list<Rectangle> *> List;
    Character *player;
    Rectangle player_area;

public:
    Collision(Character *player);

    void LoadList(std::list<Rectangle> *list1);

    bool IsColliding_X();

    bool IsColliding_y();

    bool IsCollidingPlataform();

    bool IsFlying();


};


#endif //RAYLIBTEMPLATE_COLLISION_H
