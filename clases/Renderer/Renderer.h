//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERER_H
#define RAYLIBTEMPLATE_RENDERER_H

#include "../Map/Map.h"
#include "../Personaje/Player.h"

class Renderer {
private:
    Map Level;
    Player *Character;
public:
    Renderer(Map &level , Player *&Character);

    void draw_Map();

    void draw_Character();

};


#endif //RAYLIBTEMPLATE_RENDERER_H
