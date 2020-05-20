//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_ENTITY_H
#define RAYLIBTEMPLATE_ENTITY_H


#include <raylib.h>
#include <string>
#include <vector>
class Entity {
protected:
    std::string filePathText;
    Vector2 Entity_pos{};
    std::vector<int> maxCol;
public:
    Entity();

    Entity(std::string file, Vector2 pos, std::vector<int> Max_Col);

    void Set_x(float d);

    void Set_y(float d);

    Vector2 &get_Entity_Pos() ;

    ~Entity();
};


#endif //RAYLIBTEMPLATE_ENTITY_H
