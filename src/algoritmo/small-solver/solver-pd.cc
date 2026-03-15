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
 * @file solver-pd.cc
 * @brief Implementación de SolverPD para resolver el caso base de un día
 *        usando programación dinámica.
 * @date Mar 15 2026
 * @version 1.0
 */

#include "solver-pd.h"

#include <stdexcept>
#include <vector>

#include "instancia-empleados.h"
#include "solucion-empleados.h"

/**
 * @brief Resuelve una instancia pequeña (un día) con programación dinámica.
 *
 * Modela la asignación como una tabla DP donde cada empleado puede asignarse
 * como máximo a un turno y cada turno a lo sumo a un empleado en el día 0.
 * Luego reconstruye la solución mediante backtracking sobre la matriz auxiliar.
 *
 * @param inst Instancia del problema a resolver.
 * @return Puntero a la solución construida para el caso base.
 * @throws std::invalid_argument Si la instancia no es de tipo InstanciaEmpleados.
 */
Solucion* SolverPD::ResolverDiaPequeño(Instancia* inst) {
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
  if (inst_emp == nullptr) {
    throw std::invalid_argument("Error: la instancia no es de tipo InstanciaEmpleados");
  }
  int num_emp    = inst_emp->GetNumEmpleados();
  int num_turnos = inst_emp->GetNumTurnos();
  int dia        = 0;
  std::vector<int> slots;
  for (int t = 0; t < num_turnos; ++t) {
    int min_emp = inst_emp->GetMinTurnos(dia, t);
    for (int p = 0; p < min_emp; ++p) {
      slots.push_back(t);
    }
  }
  int K = slots.size();
  SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
  if (K == 0) {
    return sol;
  }
  std::vector<std::vector<int>> tabla(
      num_emp + 1, std::vector<int>(K + 1, 0));
  std::vector<std::vector<bool>> asignado(
      num_emp + 1, std::vector<bool>(K + 1, false));
  for (int e = 1; e <= num_emp; ++e) {
    for (int k = 1; k <= K; ++k) {
      int turno          = slots[k - 1];
      int sat_no_asignar = tabla[e - 1][k];
      int sat_asignar    = tabla[e - 1][k - 1] +
                           inst_emp->GetSatisfaccion(e - 1, dia, turno);
      if (sat_asignar > sat_no_asignar) {
        tabla[e][k]    = sat_asignar;
        asignado[e][k] = true;
      } else {
        tabla[e][k] = sat_no_asignar;
      }
    }
  }
  int k = K;
  for (int e = num_emp; e > 0 && k > 0; --e) {
    if (asignado[e][k]) {
      int turno = slots[k - 1];
      sol->SetAsignacion(e - 1, dia, turno);
      --k;
    }
  }
  return sol;
}
