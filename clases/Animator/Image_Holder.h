//
// Created by martin on 20/5/20.
//

#ifndef RAYLIBTEMPLATE_IMAGE_HOLDER_H
#define RAYLIBTEMPLATE_IMAGE_HOLDER_H

#include <string>
#include "raylib.h"
#include <vector>

class Image_Holder {
private:
    std::vector<int> maxColumn;
    Texture2D Picture{};
public:
    Image_Holder(std::vector<int> maxColumn, std::string file);

    const Texture2D &getPicture() const;

    const std::vector<int> &getMaxColumn() const;
};


#endif //RAYLIBTEMPLATE_IMAGE_HOLDER_H
