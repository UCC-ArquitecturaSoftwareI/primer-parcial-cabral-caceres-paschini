//
// Created by martin on 10/5/20.
//

#include "Collision.h"

Collision::Collision(Character *player1) {
    player = player1;
    player_area.x = player->Get_Entity_Pos().x;
    player_area.y = player->Get_Entity_Pos().y;
    player_area.width = 32;
    player_area.height = 32;

}

void Collision::LoadList(std::list<Rectangle> *list) {
    List.push_back(list);
}

bool Collision::IsColliding_X() {

    player_area.height = 32;
    player_area.x = player->Get_Entity_Pos().x;
    player_area.y = player->Get_Entity_Pos().y;

    for (auto &i: *List.front()) {
        if (CheckCollisionRecs(player_area, i)) {
            
            if (player->GetSpeed().x > 0) {
                player->Set_x(i.x - player_area.width - 1);
                player->Setspeed_x(0);
                return true;
            }

            if (player->GetSpeed().x < 0) {
                player->Set_x(i.x + i.width);
                player->Setspeed_x(0);
                return true;
            }

        }
    }
    return false;
}

bool Collision::IsColliding_y() {

    player_area.height = 32;
    player_area.x = player->Get_Entity_Pos().x;
    player_area.y = player->Get_Entity_Pos().y;


    for (auto &i: *List.front()) {
        if (CheckCollisionRecs(player_area, i)) {


            if (player->GetSpeed().y > 0) {
                player->Set_y(i.y - player_area.height - 1);
                player->Setspeed_y(0);
                return true;
            } else {
                player->Set_y(i.y + i.height + 1);
                player->Setspeed_y(0.2);
                return true;
            }
        }
    }
    return false;
}

bool Collision::IsCollidingPlataform() {

    player_area.height = 32;
    player_area.x = player->Get_Entity_Pos().x;
    player_area.y = player->Get_Entity_Pos().y;

    for (auto &i: *List.back()) {
        if (CheckCollisionRecs(player_area, i))
            if (player_area.y + player_area.height > i.y && player->GetSpeed().y > 0) {
                player->Set_y(i.y - player_area.height - 1);
                player->Setspeed_y(0);
                return true;
            }
    }
    return false;
}

bool Collision::IsFlying() {

    player_area.height = 34;

    for (auto &i: *List.front()) {
        if (CheckCollisionRecs(player_area, i))
            return false;
    }

    for (auto &i: *List.back()) {
        if (CheckCollisionRecs(player_area, i))
            return false;
    }
    return true;
}



