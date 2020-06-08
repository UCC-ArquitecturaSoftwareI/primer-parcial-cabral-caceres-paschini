//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_SLIME_H
#define RAYLIBTEMPLATE_SLIME_H

#include "../../Entity/Entity.h"

class Slime : public Entity {
    private:
    public:
        Slime(std::string file, Vector2 playpos) : Entity(std::move(file), playpos,{9,9},Vector2{44, 30}) {}

};


#endif //RAYLIBTEMPLATE_SLIME_H
