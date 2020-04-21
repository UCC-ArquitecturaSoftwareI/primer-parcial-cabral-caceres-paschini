//
// Created by martin on 21/3/20.
//

#include <string>
#include "Player.h"

/**
 * This func creates the the payer entity into the program(Texture and position wise)
 * @param text: Is the path of the texture
 * @param navePos: Is the position of the player
 */
Player::Player(std::string text, const Vector2 &playpos) : player_pos(playpos) {

    player = LoadTexture(text.c_str());
}
/**
 * this func moves the player in the x coordinates
 * @param d
 */
void Player::move_x(float d) {
    player_pos.x += d;
}/**
 * this function moves the player in the y coordinate
 * @param d
 */
void Player::move_y(float d) {
    player_pos.y += d;
}

const Vector2 &Player::getPlayerPos() const {
    return player_pos;
}

const Texture2D &Player::getPlayer() const {
    return player;
}
