//
// Created by martin on 21/3/20.
//

#include <string>
#include <sstream>
#include "Character.h"

/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Character::Acelerate_x(float d) {
    if (std::abs(player_Spd.x) < 2.6)
        player_Spd.x += d;

}

void Character::Deacelerate_x(float d) {
    player_Spd.x += d;
}

void Character::Jump_y(float d) {
    player_Spd.y -= d;
}

void Character::Move_x() {
    Entity_pos.x += player_Spd.x;
}

void Character::Move_y() {
    Entity_pos.y += player_Spd.y;
}

void Character::Setspeed_x(float d) {
    player_Spd.x = d;
}

void Character::Setspeed_y(float d) {
    player_Spd.y = d;
}

Vector2 Character::GetSpeed() {
    return player_Spd;
}

void Character::Change_life(int d) {
    life += d;
    Set_x(32);
    Set_y(592);
}

void Character::Gain_poitns(float d) {
    points += d;
}

std::string Character::Get_life() {
    std::string temp;
    temp = std::to_string(life);
    const char *c = nullptr;
    c = temp.c_str();
    return c;
}

std::string Character::GetPoints() {
    std::string temp;
    temp = std::to_string(points);
    const char *c = nullptr;
    c = temp.c_str();
    return c;
}

bool Character::Is_alive() {
    return life == 0;
}

int Character::Get_life_Num() {
    return life;
}








