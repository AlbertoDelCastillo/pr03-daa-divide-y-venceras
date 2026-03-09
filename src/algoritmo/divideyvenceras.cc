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
 * @brief Implementación de la clase abstracta DivideYVenceras para algoritmos de tipo divide y vencerás.
 * @date Mar 8 2026
 * @version 1.0
 */

#include "divideyvenceras.h"

/**
 * @brief Constructor de la clase DivideYVenceras.
 * Inicializa el atributo problema_inicial_ con la instancia recibida.
 * @param inst Instancia inicial del problema.
 */
DivideYVenceras::DivideYVenceras(Instancia* inst) : problema_inicial_{inst} {}

/**
 * @brief Método ejecutar.
 * Llama al método Solve con el valor del atributo instancia y
 * asigna el resultado al atributo solucion_problema_.
 */
void DivideYVenceras::Ejecutar() {
  Instancia* inst = this->problema_inicial_;
  int tamaño = inst->GetTamaño();
  this->solucion_problema_->CopiarValores(this->Solve(inst, tamaño));
}

/**
 * @brief Método Solve con la lógica de Divide y Vencerás.
 * Aplica recursivamente la metodología, utilizando los métodos Small, SolveSmall, Divide y Combine.
 * @param inst Instancia a resolver.
 * @param tamaño Tamaño de la instancia.
 * @return Solución al problema.
 */
Solucion* DivideYVenceras::Solve(Instancia* inst, int tamaño) {
  if (Small(inst)) {
    return SolveSmall(inst);
  } else {
    std::vector<Instancia*> m = Divide(inst, tamaño); 
    Solucion* s1 = Solve(m[0], m[0]->GetTamaño());
    Solucion* s2 = Solve(m[1], m[1]->GetTamaño());
    Solucion* S = Combine(s1, s2);
    delete m[0];
    delete m[1];
    return S; 
  }
}