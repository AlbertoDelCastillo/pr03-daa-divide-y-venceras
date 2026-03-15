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
 * @file solver-gready.cc
 * @brief Implementación de SolverGready para resolver el caso base de un día
 *        usando un algoritmo voraz.
 * @date Mar 15 2026
 * @version 1.0
 */

#include "solver-gready.h"

#include <limits>
#include <stdexcept>

#include "instancia-empleados.h"
#include "solucion-empleados.h"

/**
 * @brief Resuelve una instancia pequeña (un día) con un algoritmo voraz.
 *
 * Para cada turno, selecciona el empleado disponible con mayor satisfacción
 * y lo asigna a ese turno. Un empleado solo puede ser asignado a un turno
 * por día.
 *
 * @param inst Instancia del problema a resolver.
 * @return Puntero a la solución construida para el caso base.
 * @throws std::invalid_argument Si la instancia no es de tipo InstanciaEmpleados.
 */
Solucion* SolverGready::ResolverDiaPequeño(Instancia* inst) {
	InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
	if (inst_emp == nullptr) {
		throw std::invalid_argument("Error: la instancia no es de tipo InstanciaEmpleados");
	}
	int num_emp = inst_emp->GetNumEmpleados();
	int num_turnos = inst_emp->GetNumTurnos();
	SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
	for (int t = 0; t < num_turnos; ++t) {
		int mejor_emp = -1;
		int mejor_sat = std::numeric_limits<int>::min();
		for (int e = 0; e < num_emp; ++e) {
			if (sol->GetAsignacion(e, 0) != -1) {
				continue;
			}
			int sat = inst_emp->GetSatisfaccion(e, 0, t);
			if (sat > mejor_sat) {
				mejor_sat = sat;
				mejor_emp = e;
			}
		}
		if (mejor_emp != -1) {
			sol->SetAsignacion(mejor_emp, 0, t);
		}
	}
	return sol;
}
