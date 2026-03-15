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
 * @file solver-pd.h
 * @brief Declaración de la clase SolverPD para resolver el caso base
 *        mediante programación dinámica.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef SOLVER_PD_H
#define SOLVER_PD_H

#include <stdexcept>
#include <vector>

#include "instancia-empleados.h"
#include "small-solver.h"
#include "solucion-empleados.h"

/**
 * @class SolverPD
 * @brief Implementación de SmallSolver basada en programación dinámica.
 *
 * Resuelve instancias pequeñas de un único día maximizando la satisfacción
 * total bajo las restricciones de asignación de empleados a turnos.
 */
class SolverPD : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* isnt) override;
};

#endif