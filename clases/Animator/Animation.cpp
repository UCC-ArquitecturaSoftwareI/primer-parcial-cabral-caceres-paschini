//
// Created by Martin on 26/04/2020.
//

#include "Animation.h"


Animation::Animation(Image_Holder *img) {
    currentColumn = 0;
    currentRow = 0;
    frameRec = {0.0f, 0.0f, 32, 32};
    image = img;
}


void Animation::Animate(Vector2 pos) {

    frameRec = {static_cast<float>(currentColumn * 32.0), static_cast<float>(currentRow * 32.0), 32, 32};
    DrawTextureRec(image->getPicture(), frameRec, pos, WHITE);
    currentColumn = ++currentColumn % image->getMaxColumn()[currentRow];
}

void Animation::setCurrentRow(int currentRow) {
    Animation::currentRow = currentRow;
}
