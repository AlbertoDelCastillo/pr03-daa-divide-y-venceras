#ifndef SOLUCION_VECTOR_H
#define SOLUCION_VECTOR_H

#include <iostream>
#include <vector>

#include "solucion.h"

class SolucionVector : public Solucion {
 public:
  /**
   * Constructor de la clase
   */
  SolucionVector(int tamaño = 0);

  /**
   * Metodo virtual para mostrar los valores de la solucion
   */
  void Mostrar() override;

  /**
   * Metodo virtual para copiar el valor de de una solucion
   * @param otro Otra solucion la cual se va a copiar los datos
   */
  void CopiarValores(Solucion* otra) override;

 private:
  std::vector<int> datos_;
};

#endif