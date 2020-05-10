//
// Created by Camila Cabral on 28/04/2020.
//

#ifndef RAYLIBTEMPLATE_FRUTA_H
#define RAYLIBTEMPLATE_FRUTA_H

#include <raylib.h>
#include <iostream>
#include <string>
using namespace std;
class Fruta{
private:
    Texture2D frutas;
    Rectangle rect;
    Vector2 fruta_position;
    int tipo;
public:
    Fruta(const Vector2 &frutaPosition, int tipo);

    Fruta(){
            frutas=LoadTexture("resources/FRUTAS.png");
            rect={0,0,444,32};
    }

    void desaparecer();
    void draw();

};
#endif //RAYLIBTEMPLATE_FRUTA_H
