//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_PLANT_H
#define RAYLIBTEMPLATE_PLANT_H

#include "../../Entity/Entity.h"

#include "../Enemies.h"

class Plant : public Enemies {
private:

public:
    Plant(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {44, 42};
        maxCol = {7, 7, 10, 10};

    }

    void move_x();

    void move_y();

};


#endif //RAYLIBTEMPLATE_PLANT_H
