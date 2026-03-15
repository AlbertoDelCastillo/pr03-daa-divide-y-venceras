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
 * @file solver-gready.h
 * @brief Declaración de la clase SolverGready para resolver el caso base
 *        mediante una estrategia voraz.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef SOLVER_GREADY_H
#define SOLVER_GREADY_H

#include "small-solver.h"

/**
 * @class SolverGready
 * @brief Implementación de SmallSolver basada en un enfoque voraz.
 *
 * Asigna empleados a turnos maximizando localmente la satisfacción para
 * resolver instancias pequeñas de un único día.
 */
class SolverGready : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* isnt) override;
};

#endif