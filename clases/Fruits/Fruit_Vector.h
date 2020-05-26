//
// Created by martin on 21/5/20.
//

#ifndef RAYLIBTEMPLATE_FRUIT_VECTOR_H
#define RAYLIBTEMPLATE_FRUIT_VECTOR_H

#include "Fruits.h"
#include <vector>

class Fruit_Vector {
private:
    std::vector<Fruits *> Fruits_Vec;
public:
    Fruit_Vector(std::vector<Vector2> Pos_fruits);

    std::vector<Fruits *> *Get_Vec_pointer();

    void Set_fruit_type();

    void Call_Animator();

};


#endif //RAYLIBTEMPLATE_FRUIT_VECTOR_H
