//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_COLLISION_H
#define RAYLIBTEMPLATE_COLLISION_H

#include <raylib.h>
#include <list>
#include "../Personaje/Player.h"


class Collision {
private:
    std::list<Rectangle> *List;
    Player *player;
    Rectangle player_area;
public:
    Collision(std::list<Rectangle> *list1, Player *player);

    void IsColliding_X();

    void IsColliding_y();


};


#endif //RAYLIBTEMPLATE_COLLISION_H
