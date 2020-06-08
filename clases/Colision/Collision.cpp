//
// Created by martin on 10/5/20.
//

#include "Collision.h"

Collision::Collision(Character *player1) {
    player = player1;
    player_area = {player->Get_Entity_Pos().x, player->Get_Entity_Pos().y, 32, 32};
    Fruit_area = {0, 0, 16, 16};

}

void Collision::Load_Vector(std::vector<Fruits *> *vec) {
    Fruits_Vec = vec;
}

void Collision::Load_Vector(std::vector<Rectangle> *vec, int Dat) {
    switch (Dat) {
        case 0:
            Floor_Wall = vec;
            return;
        case 1:
            Plataform = vec;
            return;
        case 2:
            Traps = vec;
            return;
        default:
            std::cout<<"Lista incorrecta"<<std::endl;
            return;
    }
}


bool Collision::IsColliding_X() {

    player_area = {player->Get_Entity_Pos().x, player->Get_Entity_Pos().y, 32, 32};

    for (auto &i: *Floor_Wall) {
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

    player_area = {player->Get_Entity_Pos().x, player->Get_Entity_Pos().y, 32, 32};

    for (auto &i: *Floor_Wall) {
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

    player_area = {player->Get_Entity_Pos().x, player->Get_Entity_Pos().y, 32, 32};

    for (auto &i: *Plataform) {
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

    player_area = {player->Get_Entity_Pos().x + 2, player->Get_Entity_Pos().y, 30, 34};

    for (auto &i: *Floor_Wall) {
        if (CheckCollisionRecs(player_area, i))
            return false;
    }

    for (auto &i: *Plataform) {
        if (CheckCollisionRecs(player_area, i))
            return false;
    }
    return true;
}


bool Collision::IsCollecting() {

    int count = 0;
    for (auto i : *Fruits_Vec) {
        count++;
        Fruit_area.x = i->Get_Entity_Pos().x;
        Fruit_area.y = i->Get_Entity_Pos().y;
        if (CheckCollisionRecs(player_area, Fruit_area)) {
            player->Gain_poitns(i->Get_points());
            Fruits_Vec->erase(Fruits_Vec->begin() + count - 1);
            delete i;
            return true;
        }
    }
    return false;
}

bool Collision::Is_getting_damage() {
    for (auto &i: *Traps) {
        if (CheckCollisionRecs(player_area, i)) {
            player->Change_life(-1);
            return true;
        }
    }
    return false;
}





