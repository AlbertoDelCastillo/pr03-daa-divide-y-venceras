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
  /**
   * @brief Constructor de MergeSort.
   * Inicializa el algoritmo con la instancia a ordenar.
   * @param inst Instancia inicial a ordenar.
   */
  MergeSort(Instancia* inst);

  /**
   * @brief Destructor por defecto.
   */
  ~MergeSort() = default;

 private:
  /**
   * @brief Determina si la instancia es suficientemente pequeña para resolver directamente.
   * Caso base: instancia de tamaño <= 1.
   * @param inst Instancia a evaluar.
   * @return true si el tamaño es <= 1, false en caso contrario.
   */
  bool Small(Instancia* inst) override;

  /**
   * @brief Resuelve el caso base de una instancia pequeña.
   * Si la instancia tiene 0 o 1 elemento, ya está ordenada.
   * @param inst Instancia pequeña a resolver.
   * @return Solución ordenada de la instancia.
   */
  Solucion* SolveSmall(Instancia* inst) override;

  /**
   * @brief Divide la instancia en dos mitades iguales.
   * Separa el vector en dos subinstancias para aplicar recursión.
   * @param inst Instancia a dividir.
   * @param tamaño Tamaño de la instancia.
   * @return Vector con dos subinstancias.
   */
  std::vector<Instancia*> Divide(Instancia* inst) override;

  /**
   * @brief Combina dos soluciones ordenadas en una sola solución ordenada.
   * Realiza el proceso de mezcla (merge) de dos vectores ordenados.
   * @param sol_parcial_1 Primera solución parcial ordenada.
   * @param sol_parcial_2 Segunda solución parcial ordenada.
   * @return Solución combinada y ordenada.
   */
  Solucion* Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) override;
};

#endif