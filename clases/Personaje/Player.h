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
    Vector2 player_Spd{};
    std::vector<int> maxCol;

public:

    Player();

    void setClass(std::string file, Vector2 playpos);

    void Acelerate_x(float d);

    void Deacelerate_x(float d);

    void Jump_y(float d);

    void Move_x();

    void Move_y();

    Vector2 &getPlayerPos() ;

    const std::string &getFilePathText() const;

    const std::vector<int> &getMaxCol() const;

    void Set_x(float d);

    void Set_y(float d);

    void Setspeed_x(float d);

    void Setspeed_y(float d);

    Vector2 GetSpeed();

};


#endif //RAYLIBTEMPLATE_NAVE_H
