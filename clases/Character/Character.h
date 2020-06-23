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
    float Spd_Multi;
    float Max_Speed;
    int Fruits_Left;
    int life;
    int Invulnerable = 0;
    Vector2 Time;
public:

    Character(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                    std::move(Max_Col),
                                                                                    Vector2{32, 32}) {
        player_Spd = {0, 0.1};
        Fruits_Left = 35;
        life = 3;
        Time = {0, 0};
        Spd_Multi = 1;
        Max_Speed = 3;
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

    void Collect();

    int Get_life_Num();

    bool Is_alive();

    int Get_Fruits_left();

    void SetMin(int F);

    void SetSec(int F);

    const Vector2 &getTime() const;

    void SetInvulnerable(int invulnerable);

    void LessInv();

    int GetInvulnerable();

    void SetSpdMulti(float spdMulti);

    void Set_MaxSpeed(float Max);
};


#endif //RAYLIBTEMPLATE_NAVE_H