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
	int num_emp = inst_emp->GetNumEmpleados();
	int num_turnos = inst_emp->GetNumTurnos();
	SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
	std::vector<std::vector<int>> tabla_puntuaciones(
			num_emp + 1, std::vector<int>(num_turnos + 1, 0));
	std::vector<std::vector<bool>> asignado(
			num_emp + 1, std::vector<bool>(num_turnos + 1, false));
	for (int emp_actual = 1; emp_actual <= num_emp; ++emp_actual) {
		for (int turnos_actual = 1; turnos_actual <= num_turnos; ++turnos_actual) {
			int sat_no_asignar = tabla_puntuaciones[emp_actual - 1][turnos_actual];
			int sat_asignar = tabla_puntuaciones[emp_actual - 1][turnos_actual - 1] +
					inst_emp->GetSatisfaccion(emp_actual - 1, 0, turnos_actual - 1);
			if (sat_asignar > sat_no_asignar) {
				tabla_puntuaciones[emp_actual][turnos_actual] = sat_asignar;
				asignado[emp_actual][turnos_actual] = true;
			} else {
				tabla_puntuaciones[emp_actual][turnos_actual] = sat_no_asignar;
			}
		}
	}
	int turnos_actual = num_turnos;
	for (int emp_actual = num_emp; emp_actual > 0 && turnos_actual > 0; --emp_actual) {
		if (asignado[emp_actual][turnos_actual]) {
			sol->SetAsignacion(emp_actual - 1, 0, turnos_actual - 1);
			--turnos_actual;
		}
	}
	return sol;
}
