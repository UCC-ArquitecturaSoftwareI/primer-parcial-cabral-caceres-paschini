/**
 * @title       Clase State
 * @file        State.h
 * @version     1.0
 * @date        10/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_STATE_H
#define RAYLIBTEMPLATE_STATE_H

/**
 * @class State
 * @brief
 */
class State {
private:
public:
    /**
     * funcion virtual pura
     */
    virtual void On() = 0;
    /**
     * funcion virual pura
     */
    virtual int Off() = 0;
};


#endif //RAYLIBTEMPLATE_STATE_H
