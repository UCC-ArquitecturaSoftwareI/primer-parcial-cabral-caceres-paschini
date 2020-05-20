//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_FRUITS_H
#define RAYLIBTEMPLATE_FRUITS_H


#include <raylib.h>
#include <string>
#include <vector>
#include "../Entity/Entity.h"

class Fruits : public Entity {
private:
    bool picked_up;
    int points;
public:

    Fruits(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos,
                                                                                 std::move(Max_Col)) {
        picked_up = false;
        points = 1;
    }
};


#endif //RAYLIBTEMPLATE_FRUITS_H
