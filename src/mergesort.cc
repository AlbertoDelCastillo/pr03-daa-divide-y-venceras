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

#include "mergesort.h"
#include <iostream>
#include <vector>

/**
 * @brief Constructor de MergeSort.
 * Inicializa el algoritmo con la instancia a ordenar.
 * @param inst Instancia inicial a ordenar.
 */
MergeSort::MergeSort(Instancia* inst) : DivideYVenceras(inst) {
  solucion_problema_ = new SolucionVector(inst->GetTamaño());
}

/**
 * @brief Determina si la instancia es suficientemente pequeña para resolver directamente.
 * Caso base: instancia de tamaño <= 1.
 * @param inst Instancia a evaluar.
 * @return true si el tamaño es <= 1, false en caso contrario.
 */
bool MergeSort::Small(Instancia* inst) {
  return inst->GetTamaño() <= 1;
}

/**
 * @brief Resuelve el caso base de una instancia pequeña.
 * Si la instancia tiene 0 o 1 elemento, ya está ordenada.
 * @param inst Instancia pequeña a resolver.
 * @return Solución ordenada de la instancia.
 */
Solucion* MergeSort::SolveSmall(Instancia* inst) {
  InstanciaVector* instancia_vec = dynamic_cast<InstanciaVector*>(inst);
  SolucionVector* solucion = new SolucionVector(inst->GetTamaño());
  for (int i = 0; i < inst->GetTamaño(); ++i) {
    solucion->SetDato(i, instancia_vec->GetDato(i));
  }
  return solucion;
}

/**
 * @brief Divide la instancia en dos mitades iguales.
 * Separa el vector en dos subinstancias para aplicar recursión.
 * @param inst Instancia a dividir.
 * @param tamaño Tamaño de la instancia.
 * @return Vector con dos subinstancias.
 */
std::vector<Instancia*> MergeSort::Divide(Instancia* inst, int tamaño) {
  InstanciaVector* instancia = dynamic_cast<InstanciaVector*>(inst);
  std::vector<Instancia*> resultado;
  int mitad = tamaño / 2;
  InstanciaVector* primera = new InstanciaVector();
  InstanciaVector* segunda = new InstanciaVector();
  for (int i = 0; i < mitad; ++i) {
    primera->AgregarDato(instancia->GetDato(i));
  }
  for (int i = mitad; i < tamaño; ++i) {
    segunda->AgregarDato(instancia->GetDato(i));
  }
  resultado.push_back(primera);
  resultado.push_back(segunda);
  return resultado;
}

/**
 * @brief Combina dos soluciones ordenadas en una sola solución ordenada.
 * Realiza el proceso de mezcla (merge) de dos vectores ordenados.
 * @param sol_parcial_1 Primera solución parcial ordenada.
 * @param sol_parcial_2 Segunda solución parcial ordenada.
 * @return Solución combinada y ordenada.
 */
Solucion* MergeSort::Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) {
  SolucionVector* sol1 = dynamic_cast<SolucionVector*>(sol_parcial_1);
  SolucionVector* sol2 = dynamic_cast<SolucionVector*>(sol_parcial_2);
  int tamaño_total = sol1->GetTamaño() + sol2->GetTamaño();
  SolucionVector* solucion_combinada = new SolucionVector(tamaño_total);
  int i = 0;
  int j = 0;
  int k = 0;
  while (i < sol1->GetTamaño() && j < sol2->GetTamaño()) {
    if (sol1->GetDato(i) <= sol2->GetDato(j)) {
      solucion_combinada->SetDato(k, sol1->GetDato(i));
      i++;
    } else {
      solucion_combinada->SetDato(k, sol2->GetDato(j));
      j++;
    }
    k++;
  }
  while (i < sol1->GetTamaño()) {
    solucion_combinada->SetDato(k, sol1->GetDato(i));
    i++;
    k++;
  }
  while (j < sol2->GetTamaño()) {
    solucion_combinada->SetDato(k, sol2->GetDato(j));
    j++;
    k++;
  }
  return solucion_combinada;
}