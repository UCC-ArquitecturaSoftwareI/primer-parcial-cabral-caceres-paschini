//
// Created by Martin on 08/04/2020.
//

#ifndef RAYLIBTEMPLATE_BACKGROUND_H
#define RAYLIBTEMPLATE_BACKGROUND_H

#include <raylib.h>
#include <string>


class Background {
private:
    Texture2D Map;
public:
    Background(std::string);

    void draw();
};


#endif //RAYLIBTEMPLATE_BACKGROUND_H
