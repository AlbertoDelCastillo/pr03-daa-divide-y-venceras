/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 4: Programación Dinámica - Patrón Factory
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @file solver-greedy-mejorado.h
 * @brief Declaración de SolverGreedyMejorado, variante del Greedy que itera
 *        por empleados ordenados por satisfacción máxima en lugar de por turnos.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef SOLVER_GREEDY_MEJORADO_H
#define SOLVER_GREEDY_MEJORADO_H

#include "small-solver.h"
#include "instancia-empleados.h"
#include "solucion-empleados.h"

/**
 * @class SolverGreedyMejorado
 * @brief Implementación de SmallSolver basada en un enfoque voraz mejorado.
 *
 * Ordena los empleados de mayor a menor satisfacción máxima y asigna cada
 * uno al turno sin cubrir donde más satisfacción aporte. Esto evita que el
 * primer turno en orden se lleve al mejor empleado global cuando ese empleado
 * sería más valioso en otro turno.
 */
class SolverGreedyMejorado : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* inst) override;
};

#endif