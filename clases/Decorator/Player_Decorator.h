//
// Created by martin on 23/6/20.
//

#ifndef RAYLIBTEMPLATE_PLAYER_DECORATOR_H
#define RAYLIBTEMPLATE_PLAYER_DECORATOR_H

#include "../Character/Character.h"
#include "../Power_Ups/Power_Ups.h"
#include "../Power_Ups/Powers/Power_A.h"
#include "../Power_Ups/Powers/Power_B.h"
#include "../Power_Ups/Powers/Power_C.h"
#include "../Power_Ups/Powers/Power_D.h"
#include "../Power_Ups/Powers/Power_E.h"


class Player_Decorator {
private:
    Power_Ups *Power;
    Character *Player;
    Animation *Ani;
    int Cu_Power;
public:
    Player_Decorator(Character *chara);

    void DrawFx();

    bool Get_Timer();

    void Reduce_Timer();

    ~Player_Decorator();

    void Activate_Power();

    int Get_Type();

};


#endif //RAYLIBTEMPLATE_PLAYER_DECORATOR_H
