//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_FAT_BIRD_H
#define RAYLIBTEMPLATE_FAT_BIRD_H

#include "../Enemies.h"

class Fat_Bird : public Enemies {
private:

public:
    Fat_Bird(std::string file, Vector2 playpos) : Enemies(std::move(file), playpos) {
        Proportion = {40, 48};
        maxCol = {3, 3, 7};
        State_y =1;
    }

    void move_x();

    void move_y();

};


#endif //RAYLIBTEMPLATE_FAT_BIRD_H
