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
 * @file quicksort.h
 * @brief Declaración de la clase QuickSort para ordenación mediante divide y vencerás.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "divideyvenceras.h"
#include "instancia-vector.h"
#include "solucion-vector.h"
#include <vector>
#include <stack>

/**
 * @class QuickSort
 * @brief Implementa el algoritmo de ordenación rápida (QuickSort) usando el patrón Divide y Vencerás.
 * Hereda de DivideYVenceras y define los métodos virtuales necesarios para la resolución.
 * El pivote se gestiona mediante una pila para asegurar que cada nivel recursivo utiliza el pivote correcto al combinar las soluciones.
 */
class QuickSort : public DivideYVenceras {
 public:
  QuickSort(Instancia*);

 private:
  bool Small(Instancia*) override;
  Solucion* SolveSmall(Instancia*) override;
  std::vector<Instancia*> Divide(Instancia*) override;
  Solucion* Combine(Solucion*, Solucion*) override;
  std::stack<int> pila_pivotes_; 
};

#endif