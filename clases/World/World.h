//
// Created by martin on 10/5/20.
//

#ifndef RAYLIBTEMPLATE_WORLD_H
#define RAYLIBTEMPLATE_WORLD_H

#include "../Personaje/Player.h"


class World {
private:
    float Grav;
    float Fric;
    Player *player;
public:
    World(Player *player1);

    void Friction();

    void Gravity();
};



#endif //RAYLIBTEMPLATE_WORLD_H
