//
// Created by martin on 8/6/20.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_H
#define RAYLIBTEMPLATE_ENEMIES_H

#include "../Entity/Entity.h"

class Enemies : public Entity {
protected:
    int State_x;
    int State_y;
    int Idle_Counter;
public:
    Enemies(std::string file, Vector2 playpos) : Entity(file, playpos, {1}, {1, 1}) {
        filePathText = file;
        Entity_pos = playpos;
        State_x = 0;
        State_y = 0;
        Idle_Counter = 0;
    }

    virtual void move_x() = 0;

    virtual void move_y() = 0;

    int Get_State_x();

    int Get_State_y();

    int Get_Counter();

    void Set_Sate_x(int s);

    void Set_Sate_y(int s);
};


#endif //RAYLIBTEMPLATE_ENEMIES_H
