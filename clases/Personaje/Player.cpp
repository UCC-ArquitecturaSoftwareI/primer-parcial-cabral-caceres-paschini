//
// Created by martin on 21/3/20.
//

#include <string>
#include "Player.h"

/**
 * This func creates the the payer entity into the program
 * @param navePos: Is the position of the player
 */
Player::Player(std::string file, Vector2 playpos) {
    player_pos = playpos;
    filePathText = file;
    maxCol={6, 5, 5, 1, 1, 10,10,11,11,4,4};
}

/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Player::move_x(float d) {
    player_pos.x += d;
}

void Player::jump_y() {
    player_pos.y -= 2;
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



