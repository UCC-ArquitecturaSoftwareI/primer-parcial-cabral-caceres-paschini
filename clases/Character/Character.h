//
// Created by martin on 21/3/20.
//
#ifndef RAYLIBTEMPLATE_NAVE_H
#define RAYLIBTEMPLATE_NAVE_H

#include <raylib.h>
#include <string>
#include <utility>
#include <vector>
#include "../Entity/Entity.h"


class Character : public Entity {
private:
    Vector2 player_Spd{};
    int points;
    int life;
public:

    Character(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                     std::move(Max_Col),
                                                                                    Vector2{32, 32}) {
        player_Spd = {0, 0.1};
        points = 0;
        life = 3;
    }

    void Acelerate_x(float d);

    void Deacelerate_x(float d);

    void Jump_y(float d);

    void Move_x();

    void Move_y();

    void Setspeed_x(float d);

    void Setspeed_y(float d);

    Vector2 GetSpeed();

    void Change_life(int d);

    void Gain_poitns(float d);

    int Get_life();

    std::string GetPoints();

};


#endif //RAYLIBTEMPLATE_NAVE_H
