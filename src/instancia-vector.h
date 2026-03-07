#ifndef INSTANCIA_VECTOR_H
#define INSTANCIA_VECTOR_H

#include <vector>

#include "instancia.h"

class InstanciaVector : public Instancia {
 public:
  /**
   * Constructor por defecto de la clase
   */
  InstanciaVector();

  /**
   * Constructor que especifica el tamaño del vector
   * @param tamanio Tamaño inicial del vector de datos
   */
  InstanciaVector(int tamanio);

  /**
   * Override del metodo generar aleatorio
   */
  void GenerarAleatorio() override;

  /**
   * Metodo virtual para mostrar los valores de la instancia
   */
  void Mostrar() override;

  /**
   * Metodo para obtener el tamaño de la instancia
   * @return Tamaño de la instancia
   */
  int GetTamaño() override;

  /**
   * Destructor
   */
  ~InstanciaVector() = default;
 private:
  std::vector<int> datos_;
};

#endif