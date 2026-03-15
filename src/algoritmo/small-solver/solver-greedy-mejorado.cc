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
 * @file solver-greedy-mejorado.cc
 * @brief Implementación de SolverGreedyMejorado para resolver el caso base
 *        de un día iterando por empleados en lugar de por turnos.
 * @date Mar 15 2026
 * @version 2.0
 */

#include "solver-greedy-mejorado.h"

#include <algorithm>
#include <limits>
#include <stdexcept>
#include <vector>

#include "instancia-empleados.h"
#include "solucion-empleados.h"

/**
 * @brief Resuelve una instancia pequeña (un día) con un algoritmo voraz
 *        mejorado que itera por empleados ordenados por satisfacción máxima.
 *
 * Ordena los empleados de mayor a menor satisfacción máxima. Para cada
 * empleado, prioriza asignarlo a un turno sin cubrir con mayor satisfacción.
 * Si todos los turnos están cubiertos, lo asigna al turno de mayor satisfacción
 * — igual que el Greedy original, sin forzar descansos.
 *
 * @param inst Instancia del problema a resolver.
 * @return Puntero a la solución construida para el caso base.
 * @throws std::invalid_argument Si la instancia no es de tipo InstanciaEmpleados.
 */
Solucion* SolverGreedyMejorado::ResolverDiaPequeño(Instancia* inst) {
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
  if (inst_emp == nullptr) {
    throw std::invalid_argument("Error: la instancia no es de tipo InstanciaEmpleados");
  }
  int num_emp    = inst_emp->GetNumEmpleados();
  int num_turnos = inst_emp->GetNumTurnos();
  int dia        = 0;
  SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
  std::vector<std::pair<int, int>> empleados_ordenados;
  for (int e = 0; e < num_emp; ++e) {
    int max_sat = std::numeric_limits<int>::min();
    for (int t = 0; t < num_turnos; ++t) {
      int sat = inst_emp->GetSatisfaccion(e, dia, t);
      if (sat > max_sat) max_sat = sat;
    }
    empleados_ordenados.push_back({max_sat, e});
  }
  std::sort(empleados_ordenados.begin(), empleados_ordenados.end(),
            [](const auto& a, const auto& b) { return a.first > b.first; });
  std::vector<int> asignados_por_turno(num_turnos, 0);
  for (const auto& [max_sat, e] : empleados_ordenados) {
    int mejor_turno = -1;
    int mejor_sat   = std::numeric_limits<int>::min();
    for (int t = 0; t < num_turnos; ++t) {
      bool sin_cubrir = asignados_por_turno[t] < inst_emp->GetMinTurnos(dia, t);
      if (!sin_cubrir) continue;
      int sat = inst_emp->GetSatisfaccion(e, dia, t);
      if (sat > mejor_sat) {
        mejor_sat   = sat;
        mejor_turno = t;
      }
    }
    if (mejor_turno == -1) {
      for (int t = 0; t < num_turnos; ++t) {
        int sat = inst_emp->GetSatisfaccion(e, dia, t);
        if (sat > mejor_sat) {
          mejor_sat   = sat;
          mejor_turno = t;
        }
      }
    }
    if (mejor_turno != -1) {
      sol->SetAsignacion(e, dia, mejor_turno);
      asignados_por_turno[mejor_turno]++;
    }
  }
  return sol;
}