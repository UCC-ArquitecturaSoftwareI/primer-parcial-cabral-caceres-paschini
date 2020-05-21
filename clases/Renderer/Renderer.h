//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERER_H
#define RAYLIBTEMPLATE_RENDERER_H

#include "../Map/Map.h"
#include "../Character/Character.h"
#include "../Fruits/Fruit_Vector.h"
#include "../Animator/Animation_Creator.h"


class Renderer {
private:
    Map *Level;
    Character *Chara;
    Fruit_Vector *Vector;
    Animation_Creator Ani_Creator;
    Camera2D camZoom;
public:
    Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec);

    void draw_Map();

    void UpdateDrawFrame(int State);


};


#endif //RAYLIBTEMPLATE_RENDERER_H
