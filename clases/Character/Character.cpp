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
    if (Invulnerable == 0)
        life += d;
    else
        Invulnerable--;
}

void Character::Collect() {
    Fruits_Left -= 1;
}

bool Character::Is_alive() {
    return life != 0;
}

int Character::Get_life_Num() {
    return life;
}

int Character::Get_Fruits_left() {
    return Fruits_Left;
}

void Character::SetMin(int F) {
    Time.x = F;
}

void Character::SetSec(int F) {
    Time.y = F;
}

const Vector2 &Character::getTime() const {
    return Time;
}

void Character::SetInvulnerable(int invulnerable) {
    Invulnerable = invulnerable;
}

void Character::LessInv() {
    Invulnerable--;
}

int Character::GetInvulnerable() {
    return Invulnerable;
}








