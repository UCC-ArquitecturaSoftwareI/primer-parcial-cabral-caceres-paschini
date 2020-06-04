//
// Created by martin on 1/6/20.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "../Entity/Entity.h"


class Enemies: public Entity{
private:
public:

    Enemies(std::string file, Vector2 playpos, std::vector<int> Max_Col) : Entity(std::move(file), playpos, std::move(Max_Col),Vector2{32, 32}) {}

    void Move_X(float d);


    void Move_Y(float d);

};




#endif //RAYLIBTEMPLATE_ENEMIES_H
