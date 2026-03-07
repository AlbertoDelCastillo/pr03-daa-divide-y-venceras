#ifndef MERGESORT_H
#define MERGESORT_H

#include "divideyvenceras.h"
#include "instancia-vector.h"
#include "solucion-vector.h"

class MergeSort : public DivideYVenceras {
 public:
  /**
   * Constructor de MergeSort
   * @param inst Instancia inicial a ordenar
   */
  MergeSort(Instancia* inst);

  /**
   * Destructor
   */
  ~MergeSort() = default;

 private:
  /**
   * Determina si el tamaño de la instancia es suficientemente pequeño
   * @param inst Instancia a evaluar
   * @return true si el tamaño es <= 1
   */
  bool Small(Instancia* inst) override;

  /**
   * Resuelve el caso base (instancia pequeña)
   * @param inst Instancia pequeña a resolver
   * @return Solución del caso base
   */
  Solucion* SolveSmall(Instancia* inst) override;

  /**
   * Divide la instancia en dos mitades iguales
   * @param inst Instancia a dividir
   * @param tamaño Tamaño de la instancia
   * @return Vector con dos subinstancias
   */
  std::vector<Instancia*> Divide(Instancia* inst, int tamaño) override;

  /**
   * Combina dos soluciones ordenadas en una sola solución ordenada
   * @param sol_parcial_1 Primera solución parcial
   * @param sol_parcial_2 Segunda solución parcial
   * @return Solución combinada y ordenada
   */
  Solucion* Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) override;
};

#endif