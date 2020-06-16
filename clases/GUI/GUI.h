//
// Created by martin on 8/6/20.
//

#ifndef RAYLIBTEMPLATE_GUI_H
#define RAYLIBTEMPLATE_GUI_H

#include <raylib.h>
#include <string>
#include <ctime>
#include "../Character/Character.h"

class GUI {
private:
    Rectangle Rec_1{};
    Rectangle Rec_2{};
    Rectangle Rec_3{};
    std::string Fruis_left;
    std::string Sec;
    std::string Min;
    int Seconds;
    int Minutes;
    int timer;
    Character *Player;
public:
    GUI();

    void LoadPlayer( Character *Play);

    void DrawGui(int Amount);

    void Take_Time();

};


#endif //RAYLIBTEMPLATE_GUI_H
