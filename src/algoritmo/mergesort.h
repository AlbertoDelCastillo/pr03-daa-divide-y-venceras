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
 * @brief Implementación del algoritmo MergeSort usando el patrón Divide y Vencerás.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef MERGESORT_H
#define MERGESORT_H

#include "divideyvenceras.h"
#include "instancia-vector.h"
#include "solucion-vector.h"

/**
 * @class MergeSort
 * @brief Implementa el algoritmo de ordenación MergeSort usando el patrón Divide y Vencerás.
 * Hereda de DivideYVenceras y define los métodos virtuales necesarios para la resolución.
 */
class MergeSort : public DivideYVenceras {
 public:
  MergeSort(Instancia*);
  ~MergeSort() = default;

 private:
  bool Small(Instancia*) override;
  Solucion* SolveSmall(Instancia*) override;
  std::vector<Instancia*> Divide(Instancia*) override;
  Solucion* Combine(Solucion*, Solucion*) override;
};

#endif