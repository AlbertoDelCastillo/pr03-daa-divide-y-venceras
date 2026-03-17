/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 3: Divide y Vencerás - Planificación de Empleados
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @file small-solver.h
 * @brief Declaración de la interfaz SmallSolver para resolver instancias
 *        pequeñas del problema en el caso base.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef COMBINE_H
#define COMBINE_H

#include "solucion-empleados.h"
#include "solucion.h"
#include "instancia.h"

class Combine {
 public:
  virtual Solucion* Combinar(Solucion*, Solucion*) = 0;
 protected:
  
};

#endif