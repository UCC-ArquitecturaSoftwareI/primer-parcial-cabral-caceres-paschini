//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_WORLD_H
#define RAYLIBTEMPLATE_WORLD_H

#include "../Character/Character.h"


class World {
private:
    float Grav;
    float Fric;
    Character *player;
public:
    World(Character *player1);

    void Friction();

    void Gravity();
};



#endif //RAYLIBTEMPLATE_WORLD_H
