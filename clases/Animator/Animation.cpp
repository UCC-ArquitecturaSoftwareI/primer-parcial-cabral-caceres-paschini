//
// Created by Martin on 26/04/2020.
//

#include "Animation.h"


Animation::Animation(std::string file, std::vector<int> vec) {
    currentColumn = 0;
    currentRow = 0;
    frameRec = {0.0f, 0.0f, 32, 32};
    Picture = LoadTexture(file.c_str());
    for (int &i : vec) {
        maxColumn.push_back(i);
    }
}


void Animation::Animate(Vector2 pos) {

    frameRec = {static_cast<float>(currentColumn * 32.0), static_cast<float>(currentRow * 32.0), 32, 32};
    DrawTextureRec(Picture, frameRec, pos, WHITE);
    currentColumn = ++currentColumn % maxColumn[currentRow];
}

void Animation::setCurrentRow(int currentRow) {
    Animation::currentRow = currentRow;
}
