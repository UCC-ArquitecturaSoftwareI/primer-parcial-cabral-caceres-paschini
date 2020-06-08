//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_FAT_BIRD_H
#define RAYLIBTEMPLATE_FAT_BIRD_H

#include "../../Entity/Entity.h"

class Fat_Bird : public Entity {
private:
public:
    Fat_Bird(std::string file, Vector2 playpos) : Entity(std::move(file), playpos,{3,3,7},Vector2{40, 48}) {}

};


#endif //RAYLIBTEMPLATE_FAT_BIRD_H
