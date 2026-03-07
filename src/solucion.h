#ifndef SOLUCION_H
#define SOLUCION_H

/**
 * Clase abstracta para representar la solucion al problema
 * Incluye metodo para dar valores ademas de un metodo para mostrar
 */
class Solucion {
 public:
  /**
   * Metodo virtual para mostrar los valores de la solucion
   */
  virtual void Mostrar() = 0;
};

#endif