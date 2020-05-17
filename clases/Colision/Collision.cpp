//
// Created by martin on 10/5/20.
//

#include "Collision.h"

Collision::Collision(std::list<Rectangle> *list1, Player *player1) {
    player = player1;
    List = list1;
    player_area.x = player->getPlayerPos().x;
    player_area.y = player->getPlayerPos().y;
    player_area.width = 32;
    player_area.height = 32;
}

void Collision::IsColliding_X() {

    player_area.x = player->getPlayerPos().x;
    player_area.y = player->getPlayerPos().y;

    for (auto &i: *List) {
        if (CheckCollisionRecs(player_area, i)) {

            if (player->GetSpeed().x > 0) {
                player->Set_x(i.x - player_area.width - 1);
                player->Setspeed_x(0);
                std::cout << "Spd_x: " << player->GetSpeed().x << std::endl;
                std::cout << "Spd_y: " << player->GetSpeed().y << std::endl;
                return;
            }

            if (player->GetSpeed().x < 0) {
                player->Set_x(i.x + i.width);
                player->Setspeed_x(0);
                std::cout << "Spd_x: " << player->GetSpeed().x << std::endl;
                std::cout << "Spd_y: " << player->GetSpeed().y << std::endl;
                return;
            }

        }
    }
    std::cout << "Spd_x: " << player->GetSpeed().x << std::endl;
    std::cout << "Spd_y: " << player->GetSpeed().y << std::endl;
}

void Collision::IsColliding_y() {

    player_area.x = player->getPlayerPos().x;
    player_area.y = player->getPlayerPos().y;

    for (auto &i: *List) {
        if (CheckCollisionRecs(player_area, i))

            if (player->GetSpeed().y > 0) {
                player->Set_y(i.y - player_area.height - 1);
                player->Setspeed_y(0);
                return;
            } else {
                player->Set_y(i.y + i.height + 1);
                player->Setspeed_y(0);
                return;
            }
    }
}

