//
// Created by martin on 21/3/20.
//

#include <string>
#include "Player.h"

/**
 * This func creates the the payer entity into the program
 * @param navePos: Is the position of the player
 */
Player::Player() {
    maxCol = {6, 5, 5, 1, 1, 10, 10, 11, 11, 4, 4};
    player_Spd.x = 0;
    player_Spd.y = 0.1;
}

/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Player::Acelerate_x(float d) {
    if (std::abs(player_Spd.x) < 2.4)
        player_Spd.x += d;
}

void Player::Deacelerate_x(float d) {
    player_Spd.x += d;
}

void Player::Jump_y(float d) {
    player_Spd.y -= d;
}

void Player::Move_x() {
    player_pos.x += player_Spd.x;
}

void Player::Move_y() {
    player_pos.y += player_Spd.y;
}

Vector2 &Player::getPlayerPos() {
    return player_pos;
}

const std::string &Player::getFilePathText() const {
    return filePathText;
}

const std::vector<int> &Player::getMaxCol() const {
    return maxCol;
}

void Player::Set_x(float d) {
    player_pos.x = d;
}

void Player::Set_y(float d) {
    player_pos.y = d;
}

void Player::setClass(std::string file, Vector2 playpos) {
    player_pos = playpos;
    filePathText = file;
}

void Player::Setspeed_x(float d) {
    player_Spd.x = d;
}

void Player::Setspeed_y(float d) {
    player_Spd.y = d;
}

Vector2 Player::GetSpeed() {
    return player_Spd;
}








