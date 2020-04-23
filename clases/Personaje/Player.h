//
// Created by martin on 21/3/20.
//
#include <raylib.h>
#include <string>

#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H


class Player {
private:
    Texture2D player_text;
    Vector2 player_pos;
public:
    Player(std::string file, const Vector2 &playpos);

    void move_x(float d);

    void jump_y();

    Texture2D &getPlayerText();
};


#endif //RAYLIBTEMPLATE_NAVE_H
