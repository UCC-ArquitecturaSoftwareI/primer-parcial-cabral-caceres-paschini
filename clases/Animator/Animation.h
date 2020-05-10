//
// Created by Martin on 26/04/2020.
//

#ifndef RAYLIBTEMPLATE_ANIMATION_H
#define RAYLIBTEMPLATE_ANIMATION_H

#include <string>
#include "raylib.h"
#include <vector>
#include <fstream>
#include <unistd.h>
#include <iostream>
#include <thread>

class Animation {
private:
    int currentRow;
    int currentColumn;
    std::vector<int> maxColumn;
    Texture2D Picture{};
    Rectangle frameRec{};
public:
    Animation(std::string file, std::vector<int> vec);

    void Animate(Vector2 pos);

    void setCurrentRow(int currentRow);

};


#endif //RAYLIBTEMPLATE_ANIMATION_H
