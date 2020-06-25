/**
 * @title       Clase Entity
 * @file        Entity.h
 * @version     1.0
 * @date        20/5/20.
 * @author      Martin Caceres
 * @author      Camila Cabral
 * @author      Catalina Paschini
*/
#ifndef RAYLIBTEMPLATE_ENTITY_H
#define RAYLIBTEMPLATE_ENTITY_H


#include <raylib.h>
#include <string>
#include <vector>
#include "../Animator/Animation.h"
/**
 * @class Entity
 * @brief Funcion que recorre las imagenes
 */
class Entity {
protected:
    std::string filePathText;  /** Pasa como String la cantidad de filas */
    Vector2 Entity_pos{};   /** Vector para la posicion */
    std::vector<int> maxCol;   /** vector entero para max. Columnas*/
    Animation *Ani;        /** Puntero de la Animacion*/
    Vector2 Proportion;    /** Vector de para la Proporcion*/
public:
    /**
     * Constructor que determina la cantidad maxColumnas, Filas de la imagen
     */
    Entity();
     /**
      * Constructor con asignacion
      * @param file
      * @param pos
      * @param Max_Col
      * @param Prop
      */
    Entity(std::string file, Vector2 pos, std::vector<int> Max_Col,Vector2 Prop);
   /**
    * Da un valor a una variable D a una entity_pos en eje x
    * @param d
    */
    void Set_x(float d);
   /**
    *Da un valor a una variable D a una entity_pos en eje y
    * @param d
    */
    void Set_y(float d);
    /**
     * Vector que Recupera pos
     * @return Entity_pos
     */
    Vector2 &Get_Entity_Pos() ;
    /**
     * Funcion para el Path de fila
     * @return filePathText
     */
    const std::string &GetFilePathText() const;
    /**
     * Funcion para saber maxColumn
     * @return MaxColumn
     */
    const std::vector<int> &GetMaxCol() const;
    /**
     * Agrega a la imagen la animacion
     * @param Animator
     */
    void Assign_Animator(Animation *Animator);
    /**
     * Recupera
     * @return Animacion
     */
    Animation *GetAni() const;
    /**
     * Funcion que determina la proporcion de la imagen
     * @return Proportion
     */
    const Vector2 &GetProportion() const;
    /**
     * Funcion animacion
     */
    void Animate();
     /**
      * Animacion en la Animacion de una entidad
      */
    void Animate_Still();
    /**
     * Funcion que da un valor a una variable entera
     */
    void Set_Animation(int);

};


#endif //RAYLIBTEMPLATE_ENTITY_H
