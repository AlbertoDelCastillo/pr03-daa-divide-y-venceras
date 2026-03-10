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
 * @file divideyvenceras.h
 * @brief Declaración de la clase abstracta DivideYVenceras para algoritmos de tipo divide y vencerás.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef DIVIDEYVENCERAS_H
#define DIVIDEYVENCERAS_H

#include <vector>
#include "algoritmo.h"
#include "instancia.h"
#include "solucion.h"

/**
 * @class DivideYVenceras
 * @brief Clase abstracta que representa algoritmos con metodología divide y vencerás.
 * Define un método Solve() común para todas las clases hijas, y cuatro métodos virtuales
 * que deben ser implementados por las clases derivadas: Small, SolveSmall, Divide y Combine.
 */
class DivideYVenceras : public Algoritmo {
 public:
  DivideYVenceras(Instancia*);
  void Ejecutar() override;
  Solucion* Solve(Instancia*);
  virtual bool Small(Instancia*) = 0;
  virtual Solucion* SolveSmall(Instancia*) = 0;
  virtual std::vector<Instancia*> Divide(Instancia*) = 0;
  virtual Solucion* Combine(Solucion*, Solucion*) = 0;

 protected:
  Instancia* problema_inicial_;
  Solucion* solucion_problema_;
};

#endif