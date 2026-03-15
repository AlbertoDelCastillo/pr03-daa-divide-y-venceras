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

#ifndef SMALL_SOLVER_H
#define SMALL_SOLVER_H

#include "solucion.h"
#include "instancia.h"

/**
 * @class SmallSolver
 * @brief Interfaz abstracta para resolver instancias pequeñas del problema.
 *
 * Define el contrato común de los resolvedores del caso base (por ejemplo,
 * estrategias voraces o de programación dinámica) usados por el algoritmo
 * principal de Divide y Vencerás.
 */
class SmallSolver {
 public:
  virtual Solucion* ResolverDiaPequeño(Instancia* isnt) = 0;
};

#endif