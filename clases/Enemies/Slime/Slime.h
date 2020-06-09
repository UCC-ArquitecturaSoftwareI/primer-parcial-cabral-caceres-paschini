//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_SLIME_H
#define RAYLIBTEMPLATE_SLIME_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"

class Slime : public Enemies {
private:

public:
    Slime(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 30};
        maxCol = {9, 9};
        State_x = 1;
    }

    void move_x();

    void move_y();

};


#endif //RAYLIBTEMPLATE_SLIME_H
