//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERER_H
#define RAYLIBTEMPLATE_RENDERER_H

#include "../Map/Map.h"
#include "../Character/Character.h"
#include "../Fruits/Fruit_Vector.h"
#include "../Animator/Animation_Creator.h"
#include "../Enemies/Enemies.h"
#include "../Entity/All_entity.h"
#include "../GUI/GUI.h"


class Renderer {
private:
    Map *Level;
    Character *Chara;
    Fruit_Vector *Fruits;
    Animation_Creator Ani_Creator;
    Texture2D Background;
    Camera2D camZoom;
    Entity *Life;
    All_entity *Entities;
    int frameCounter = 0;
    std::vector<Enemies *> *Bad_Guys;
    int Char_DMG = 0;
    float scrollingBack = 0.0f;
    class GUI Interface;

public:
    Renderer(Map *Mp, Character *Ch, Fruit_Vector *Vec, std::vector<Enemies *> *Ene);

    void draw_Map();

    void UpdateDrawFrame(int State);


};


#endif //RAYLIBTEMPLATE_RENDERER_H
