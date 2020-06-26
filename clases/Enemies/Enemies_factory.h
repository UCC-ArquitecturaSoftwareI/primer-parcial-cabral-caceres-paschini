/**
 * @title       Clase Enemies
 * @file        Enemies.h
 * @version     1.0
 * @date        7/6/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
 */
#ifndef RAYLIBTEMPLATE_ENEMIES_FACTORY_H
#define RAYLIBTEMPLATE_ENEMIES_FACTORY_H

#include <map>
#include "raylib.h"
#include "Fat_Bird/Fat_Bird.h"
#include "Plant/Plant.h"
#include "Slime/Slime.h"
#include "Turtle/Turtle.h"
#include <vector>
/**
 * @class Enemies_Factory
 * @brief Define una interfaz para crear un objeto, pero deja que sean las subclases quienes decidan qué clase instanciar.
 * Permite que una clase delegue en sus subclases la creación de objetos.
 */
class Enemies_factory {
private:
    /**
     * Crea un multimap con un string de llave y guardo en puntero
     */
    std::multimap<std::string, Rectangle>  *Map;
public:
    /**
     * Funcion con argumento predeterminado
     */
    Enemies_factory()= default;
    /**
     *Funcion que toma el multimap con un string de llave y guardo en puntero
     * @param M
     */
    void Set_Map( std::multimap<std::string, Rectangle> *M);
     /**
      * Funcion que añade los distintos enemigos
      * @return Vec_Enemies
      */
    std::vector<Enemies*> Make_Enemies();
};


#endif //RAYLIBTEMPLATE_ENEMIES_FACTORY_H
