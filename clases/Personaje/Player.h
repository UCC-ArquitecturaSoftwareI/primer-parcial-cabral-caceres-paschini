//
// Created by martin on 21/3/20.
//
#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H

#include <raylib.h>
#include <string>
#include "../Animator/Animation.h"
#include <vector>


class Player {
private:
    std::string filePathText;
    Vector2 player_pos{};
    std::vector<int> maxCol;
public:
    Player(std::string file, Vector2 playpos);

    void move_x(float d);

    void jump_y();

    Vector2 &getPlayerPos() ;

    const std::string &getFilePathText() const;

    const std::vector<int> &getMaxCol() const;

};


#endif //RAYLIBTEMPLATE_NAVE_H
