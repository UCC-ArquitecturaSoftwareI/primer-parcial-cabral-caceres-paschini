/**
 * @title       Clase Context
 * @file        Context.h
 * @version     1.0
 * @date        16/06/2020.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_CONTEXT_H
#define RAYLIBTEMPLATE_CONTEXT_H

#include "State.h"
/**
 * @class Context
 * @brief
 */
class Context {
private:
    State *Current_State; /**State value. Contiene el estado actual del juego*/
public:

    Context() = default; /**Variable definida por defecto*/
    /**
     * Funcion setea el valor del estado
     * @param S
     */
    void SetCurrentState(State *S) {
        Current_State = S;
    }
    /**
     * Funcion inicia el juego
     */
    void Start_State();
    /**
     * funcion que finaliza el juego
     * @return current_state
     */
    int Stop_State();

};


#endif //RAYLIBTEMPLATE_CONTEXT_H
