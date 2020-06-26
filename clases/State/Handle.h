/**
 * @title       Clase handle
 * @file        Handle.h
 * @version     1.0
 * @date        17/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */

#ifndef RAYLIBTEMPLATE_HANDLE_H
#define RAYLIBTEMPLATE_HANDLE_H

#include "State.h"
/**
 * @class Handle
 * @brief
 */
class Handle : public State {

    void On () override ;
    /**
     *
     * @return 1
     */
    int Off() override ;
};


#endif //RAYLIBTEMPLATE_HANDLE_H
