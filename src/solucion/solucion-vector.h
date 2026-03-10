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
 * @file solucion-vector.h
 * @brief Declaración de la clase SolucionVector para representar soluciones de tipo vector de enteros.
 * @date Mar 8 2026
 * @version 1.0
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
  SolucionVector(int tamaño = 0);
  void Mostrar() override;
  int GetTamaño();
  int GetDato(int indice) const;
  void SetDato(int indice, int valor);

 private:
  std::vector<int> datos_;
};

#endif