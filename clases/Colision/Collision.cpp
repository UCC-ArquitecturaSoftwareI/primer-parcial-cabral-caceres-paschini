//
// Created by martin on 10/5/20.
//

#include "Collision.h"

Collision::Collision(std::list<Rectangle> *list1, Player *player1) {
    player = player1;
    List = list1;
}

bool Collision::IsColliding() {
    Rectangle PlayerArea;
    PlayerArea.x = player->getPlayerPos().x;
    PlayerArea.y = player->getPlayerPos().y;
    PlayerArea.width = 32;
    PlayerArea.height = 32;

    for (auto &i: *List) {

        if (CheckCollisionRecs(PlayerArea, i)) {

            std::cout << "true" << std::endl;
            if (player->GetSpeed().y > 0) {
                player->Set_y(i.y - PlayerArea.height - 1);
                std::cout << "true" << std::endl;
                player->Setspeed_x(0);
                player->Setspeed_y(0);
                return true;

            }

            if (player->GetSpeed().x > 0) {
                player->Set_x(i.x - PlayerArea.width - 1);
                std::cout << "true" << std::endl;
                player->Setspeed_x(0);
                player->Setspeed_y(0);
                return true;
            }

            if (player->GetSpeed().x < 0) {
                player->Set_x(i.x + i.width + 1);
                std::cout << "true" << std::endl;
                player->Setspeed_x(0);
                player->Setspeed_y(0);
                return true;
            }

            if (player->GetSpeed().y < 0) {
                player->Set_y(i.y + i.height + 1);
                std::cout << "true" << std::endl;
                player->Setspeed_x(0);
                player->Setspeed_y(0);
                return true;
            }


        }

    }
    return false;
}


