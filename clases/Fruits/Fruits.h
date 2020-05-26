//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_FRUITS_H
#define RAYLIBTEMPLATE_FRUITS_H


#include <raylib.h>
#include <string>
#include <vector>
#include "../Entity/Entity.h"
#include <random>
#include <zconf.h>


class Fruits : public Entity {
private:
    bool picked_up;
    int points;
public:


    Fruits(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                 std::move(Max_Col), Vector2{32, 32}) {
        int val = GetRandomValue(0, 7);
        picked_up = false;
        points = 100 * val;
    }

    bool Is_picked();

    int Get_points();

    ~Fruits();

};


#endif //RAYLIBTEMPLATE_FRUITS_H
