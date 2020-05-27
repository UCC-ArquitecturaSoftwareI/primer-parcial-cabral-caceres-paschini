//
// Created by Camila Cabral on 27/05/2020.
//

#ifndef RAYLIBTEMPLATE_ENEMY_H
#define RAYLIBTEMPLATE_ENEMY_H
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
#endif //RAYLIBTEMPLATE_ENEMY_H
