//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include <list>
#include "../Personaje/Player.h"
#include <vector>


class Collision {
private:
    std::vector<std::list<Rectangle> *> List;
    Player *player;
    Rectangle player_area;

public:
    Collision(Player *player);

    void LoadList(std::list<Rectangle> *list1);

    bool IsColliding_X();

    bool IsColliding_y();

    bool IsCollidingPlataform();

    bool IsFlying();


};


#endif //RAYLIBTEMPLATE_COLLISION_H
