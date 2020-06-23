//
// Created by martin on 17/6/20.
//

#ifndef RAYLIBTEMPLATE_HANDLE_H
#define RAYLIBTEMPLATE_HANDLE_H

#include "State.h"

class Handle : public State {

    void On () override ;

    int Off() override ;
};


#endif //RAYLIBTEMPLATE_HANDLE_H
