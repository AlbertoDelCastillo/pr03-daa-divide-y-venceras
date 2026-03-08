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

  /**
   * Getter para obtener el tamaño
   * @return tamaño de los datos
   */
  int GetTamaño();

  /**
   * Obtiene el dato en la posición indicada
   */
  int GetDato(int indice) const;

  /**
   * Establece el dato en la posición indicada
   */
  void SetDato(int indice, int valor);

 private:
  std::vector<int> datos_;
};

#endif