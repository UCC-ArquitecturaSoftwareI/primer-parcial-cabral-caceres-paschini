//
// Created by martin on 21/3/20.
//

#include <string>
#include "Player.h"

/**
 * This func creates the the payer entity into the program
 * @param navePos: Is the position of the player
 */
Player::Player(std::string file, const Vector2 &playpos) : player_pos(playpos) {
    player_text = LoadTexture(file.c_str());
}

/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Player::move_x(float d) {
    player_pos.x += d;
}

void Player::jump_y() {
    player_pos.y +=5;
}

Texture2D &Player::getPlayerText() {
    return player_text;
}


