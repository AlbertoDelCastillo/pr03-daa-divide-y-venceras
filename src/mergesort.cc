#include "mergesort.h"
#include <iostream>
#include <vector>

/**
 * Constructor de MergeSort
 */
MergeSort::MergeSort(Instancia* inst) : DivideYVenceras(inst) {
  solucion_problema_ = new SolucionVector(inst->GetTamaño());
}

/**
 * Determina si el tamaño es suficientemente pequeño (caso base)
 */
bool MergeSort::Small(Instancia* inst) {
  return inst->GetTamaño() <= 1;
}

/**
 * Resuelve el caso base: una instancia con 0 o 1 elemento ya está ordenada
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
 * Divide la instancia en dos mitades iguales
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
 * Combina dos soluciones ordenadas usando merge
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