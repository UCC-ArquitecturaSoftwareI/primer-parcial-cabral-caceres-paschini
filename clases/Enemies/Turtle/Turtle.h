//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_TURTLE_H
#define RAYLIBTEMPLATE_TURTLE_H

#include "../../Entity/Entity.h"

class Turtle :public Entity {
    private:
    public:
        Turtle(std::string file, Vector2 playpos) : Entity(std::move(file), playpos,{7,7,7,7,13,13,13,13},Vector2{44, 26}) {}

};


#endif //RAYLIBTEMPLATE_TURTLE_H
