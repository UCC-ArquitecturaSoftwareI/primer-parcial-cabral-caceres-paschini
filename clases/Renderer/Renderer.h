//
// Created by Martin on 20/04/2020.
//

#ifndef RAYLIBTEMPLATE_RENDERER_H
#define RAYLIBTEMPLATE_RENDERER_H

#include "../Map/Map.h"
#include "../Personaje/Player.h"
#include <thread>

class Renderer {
private:
    Map *Level;
    Player *Character;
    Animation *Playani;
    Camera2D camZoom;
public:
    Renderer(Map *Mp, Player *Ch);

    void draw_Map();

    void UpdateDrawFrame(int State);

};


#endif //RAYLIBTEMPLATE_RENDERER_H
