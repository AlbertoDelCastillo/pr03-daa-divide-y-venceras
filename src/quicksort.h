#ifndef QUICKSORT_H
#define QUICKSORT_H

#include "divideyvenceras.h"
#include "instancia-vector.h"
#include "solucion-vector.h"
#include <vector>
#include <stack>

/**
 * @brief Clase QuickSort que implementa el algoritmo de ordenación rápida
 * usando la metodología de divide y vencerás. Hereda de DivideYVenceras
 * y define los métodos virtuales necesarios para la resolución.
 *
 * El pivote se gestiona mediante una pila para asegurar que cada nivel
 * recursivo utiliza el pivote correcto al combinar las soluciones.
 */
class QuickSort : public DivideYVenceras {
 public:
  /**
   * @brief Constructor de QuickSort
   * @param inst Instancia inicial a ordenar
   */
  QuickSort(Instancia* inst);

 private:
  /**
   * @brief Comprueba si la instancia es lo suficientemente pequeña para resolver directamente.
   * @param inst Instancia a evaluar
   * @return true si el tamaño es <= 1, false en caso contrario
   */
  bool Small(Instancia* inst) override;

  /**
   * @brief Resuelve el caso base de una instancia pequeña.
   * @param inst Instancia pequeña a resolver
   * @return Solución ordenada de la instancia
   */
  Solucion* SolveSmall(Instancia* inst) override;

  /**
   * @brief Divide la instancia usando un pivote en dos subinstancias: menores y mayores.
   * El pivote se guarda en una pila para ser recuperado en Combine.
   * @param inst Instancia a dividir
   * @param tamaño Tamaño de la instancia
   * @return Vector con dos subinstancias
   */
  std::vector<Instancia*> Divide(Instancia* inst, int tamaño) override;

  /**
   * @brief Combina dos soluciones parciales y el pivote en una solución ordenada.
   * Recupera el pivote de la pila para insertarlo en la posición correcta.
   * @param sol_parcial_1 Solución de los elementos menores
   * @param sol_parcial_2 Solución de los elementos mayores
   * @return Solución combinada y ordenada
   */
  Solucion* Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) override;

  /**
   * @brief Pila para gestionar los pivotes en cada nivel recursivo.
   */
  std::stack<int> pila_pivotes_; 
};

#endif