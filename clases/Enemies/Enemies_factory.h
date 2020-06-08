//
// Created by martin on 7/6/20.
//

#ifndef RAYLIBTEMPLATE_ENEMIES_FACTORY_H
#define RAYLIBTEMPLATE_ENEMIES_FACTORY_H

#include <map>
#include "raylib.h"
#include "Fat_Bird/Fat_Bird.h"
#include "Plant/Plant.h"
#include "Slime/Slime.h"
#include "Turtle/Turtle.h"
#include <vector>

class Enemies_factory {
private:
    std::multimap<std::string, Rectangle>  *Map;
public:
    Enemies_factory()= default;

    void Set_Map( std::multimap<std::string, Rectangle> *M);

    std::vector<Entity*> Make_Enemies();
};


#endif //RAYLIBTEMPLATE_ENEMIES_FACTORY_H
