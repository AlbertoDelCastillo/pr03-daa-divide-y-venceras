#include "quicksort.h"

/**
 * Constructor de QuickSort
 * @param inst Instancia inicial a ordenar
 */
QuickSort::QuickSort(Instancia* inst) : DivideYVenceras(inst) {
  solucion_problema_ = new SolucionVector(inst->GetTamaño());
}

/**
 * Comprueba si la instancia es lo suficientemente pequeña para resolver directamente.
 * @param inst Instancia a evaluar
 * @return true si el tamaño es <= 1, false en caso contrario
 */
bool QuickSort::Small(Instancia* inst) {
  return inst->GetTamaño() <= 1;
}

/**
 * Resuelve el caso base de una instancia pequeña.
 * @param inst Instancia pequeña a resolver
 * @return Solución ordenada de la instancia
 */
Solucion* QuickSort::SolveSmall(Instancia* inst) {
  SolucionVector* solucion = new SolucionVector(inst->GetTamaño());
  if (inst->GetTamaño() == 1) {
    InstanciaVector* instancia_vec = dynamic_cast<InstanciaVector*>(inst);
    solucion->SetDato(0, instancia_vec->GetDato(0));
  }
  return solucion;
}

/**
 * Divide la instancia usando un pivote en dos subinstancias: menores y mayores.
 * @param inst Instancia a dividir
 * @param tamaño Tamaño de la instancia
 * @return Vector con dos subinstancias
 */
std::vector<Instancia*> QuickSort::Divide(Instancia* inst, int tamaño) {
  InstanciaVector* instancia_vec = dynamic_cast<InstanciaVector*>(inst);
  std::vector<Instancia*> resultado;
  int pivote_actual = instancia_vec->GetDato(0);
  pila_pivotes_.push(pivote_actual); 
  InstanciaVector* menores = new InstanciaVector();
  InstanciaVector* mayores = new InstanciaVector();
  for (int i = 1; i < tamaño; ++i) {
    int valor = instancia_vec->GetDato(i);
    if (valor <= pivote_actual) {
      menores->AgregarDato(valor);
    } else {
      mayores->AgregarDato(valor);
    }
  }
  resultado.push_back(menores);
  resultado.push_back(mayores);
  return resultado;
}

/**
 * Combina dos soluciones parciales y el pivote en una solución ordenada.
 * @param sol_parcial_1 Solución de los elementos menores
 * @param sol_parcial_2 Solución de los elementos mayores
 * @return Solución combinada y ordenada
 */
Solucion* QuickSort::Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) {
  SolucionVector* menores = dynamic_cast<SolucionVector*>(sol_parcial_1);
  SolucionVector* mayores = dynamic_cast<SolucionVector*>(sol_parcial_2);
  int pivote_recuperado = pila_pivotes_.top();
  pila_pivotes_.pop();
  int tamaño_total = menores->GetTamaño() + 1 + mayores->GetTamaño();
  SolucionVector* resultado = new SolucionVector(tamaño_total);
  for (int i = 0; i < menores->GetTamaño(); ++i) {
    resultado->SetDato(i, menores->GetDato(i));
  }
  resultado->SetDato(menores->GetTamaño(), pivote_recuperado);
  for (int i = 0; i < mayores->GetTamaño(); ++i) {
    resultado->SetDato(menores->GetTamaño() + 1 + i, mayores->GetDato(i));
  }
  return resultado;
}