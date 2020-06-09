//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_TURTLE_H
#define RAYLIBTEMPLATE_TURTLE_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"

class Turtle : public Enemies {
private:

public:
    Turtle(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 26};
        maxCol = {7, 7, 7, 7, 13, 13, 13, 13};
        State_x =1;

    }

    void move_x();

    void move_y();

};


#endif //RAYLIBTEMPLATE_TURTLE_H
