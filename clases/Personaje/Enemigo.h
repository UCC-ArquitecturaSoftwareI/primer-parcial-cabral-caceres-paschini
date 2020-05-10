//
// Created by Camila Cabral on 25/04/2020.
//

#ifndef PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
#define PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
#include <raylib.h>
#include <string>
#include <vector>
class Enemigo {
private:
    Texture2D enemigo;
    Vector2 enemigo_pos;
public:
    Enemigo(std::string file, const Vector2 &enemPos);
    void move_x(float d);
    void move_y(float d);
    void draw();
    Vector2 &getEnemigoPos() ;
};
#endif //PRIMER_PARCIAL_CABRAL_CACERES_PASCHINI_CAMI_ENEMIGO_H
