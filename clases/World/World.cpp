//
// Created by martin on 10/5/20.
//

#include "World.h"

World::World(Character *player1) {
    player = player1;
    Fric = 0.1;
    Grav = 0.2;
}

void World::Friction() {
    if (player->GetSpeed().x > 0.00001 || player->GetSpeed().x < -0.00001) {

        if (player->GetSpeed().x > 0)
            player->Deacelerate_x(-Fric);
        else
            player->Deacelerate_x(Fric);
    } else
        player->Setspeed_x(0);
}

void World::Gravity() {
        player->Jump_y(-Grav);
}




