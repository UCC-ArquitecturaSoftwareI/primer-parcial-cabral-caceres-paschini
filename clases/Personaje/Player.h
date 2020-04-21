//
// Created by martin on 21/3/20.
//
#include <raylib.h>
#include <string>

#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H


class Player {
    Texture2D player;
    Vector2 player_pos;
public:
    Player(std::string text, const Vector2 &play_pos);

    void move_x(float d);

    void move_y(float d);

    const Vector2 &getPlayerPos() const;

    const Texture2D &getPlayer() const;
};


#endif //RAYLIBTEMPLATE_NAVE_H
