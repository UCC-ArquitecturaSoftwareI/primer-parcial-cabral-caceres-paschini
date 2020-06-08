//
// Created by martin on 20/5/20.
//
#ifndef RAYLIBTEMPLATE_ENTITY_H
#define RAYLIBTEMPLATE_ENTITY_H


#include <raylib.h>
#include <string>
#include <vector>
#include "../Animator/Animation.h"
class Entity {
protected:
    std::string filePathText;
    Vector2 Entity_pos{};
    std::vector<int> maxCol;
    Animation *Ani;
    Vector2 Proportion;
public:
    Entity();

    Entity(std::string file, Vector2 pos, std::vector<int> Max_Col,Vector2 Prop);

    void Set_x(float d);

    void Set_y(float d);

    Vector2 &Get_Entity_Pos() ;

    const std::string &GetFilePathText() const;

    const std::vector<int> &GetMaxCol() const;

    void Assign_Animator(Animation *Animator);

    Animation *GetAni() const;

    const Vector2 &GetProportion() const;

    void Animate();

    void Set_Animation(int);

};


#endif //RAYLIBTEMPLATE_ENTITY_H
