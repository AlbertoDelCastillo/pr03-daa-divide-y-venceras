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
   * Obtiene el dato en la posición indicada
   * @param indice Posición del dato
   * @return Valor del dato en esa posición
   */
  int GetDato(int indice) const;

  /**
   * Agrega un dato al final del vector
   * @param valor Valor a agregar
   */
  void AgregarDato(int valor);

  /**
   * Destructor
   */
  ~InstanciaVector() = default;

  /**
   * Establece el dato en la posición indicada
   * @param indice Posición del dato
   * @param valor Valor a establecer
   */
  void SetDato(int indice, int valor);

 private:
  std::vector<int> datos_;
};

#endif