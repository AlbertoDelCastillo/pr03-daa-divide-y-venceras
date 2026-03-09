/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 3: Divide y Vencerás - Ordenación
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @brief Implementación de la clase SolucionVector para representar soluciones de ordenación.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file solucion-vector.h
 * @brief Declaración de la clase SolucionVector para representar soluciones de tipo vector de enteros.
 */

#ifndef SOLUCION_VECTOR_H
#define SOLUCION_VECTOR_H

#include <iostream>
#include <vector>
#include "solucion.h"

/**
 * @class SolucionVector
 * @brief Representa una solución de tipo vector de enteros para algoritmos de ordenación.
 * Hereda de Solucion y permite mostrar, copiar y modificar los datos de la solución.
 */
class SolucionVector : public Solucion {
 public:
  /**
   * @brief Constructor de la clase SolucionVector.
   * Inicializa el vector de solución con el tamaño especificado.
   * @param tamaño Tamaño inicial del vector de solución.
   */
  SolucionVector(int tamaño = 0);

  /**
   * @brief Muestra los valores de la solución por pantalla.
   * Override del método virtual de Solucion.
   */
  void Mostrar() override;

  // /**
  //  * @brief Copia los valores de otra solución en esta.
  //  * Override del método virtual de Solucion.
  //  * @param otra Otra solución de la cual se van a copiar los datos.
  //  */
  // void CopiarValores(Solucion* otra) override;

  /**
   * @brief Obtiene el tamaño del vector de solución.
   * @return Tamaño de los datos.
   */
  int GetTamaño();

  /**
   * @brief Obtiene el dato en la posición indicada.
   * @param indice Posición del dato.
   * @return Valor del dato en esa posición.
   */
  int GetDato(int indice) const;

  /**
   * @brief Establece el dato en la posición indicada.
   * @param indice Posición del dato.
   * @param valor Valor a establecer.
   */
  void SetDato(int indice, int valor);

 private:
  std::vector<int> datos_; ///< Vector de datos enteros de la solución.
};

#endif