//
// Created by martin on 21/3/20.
//

#include <string>
#include <sstream>
#include "Character.h"
#include <stdlib.h>
/**
 * This func creates the the payer entity into the program
 * @param navePos: Is the position of the player
 */


/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Character::Acelerate_x(float d) {
    if ((std::abs(player_Spd.x))<2.4)
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
}

void Character::Gain_poitns(float d) {
    points += d;
}

int Character::Get_life() {
    return life;
}

std::string Character::GetPoints() {
    std::string temp;
    temp = std::to_string(points);
    const char *c = nullptr;
    c = temp.c_str();
    return c;
}








