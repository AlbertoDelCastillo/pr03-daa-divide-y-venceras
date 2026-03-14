#include "solver-gready.h"

#include <limits>
#include <stdexcept>

#include "instancia-empleados.h"
#include "solucion-empleados.h"

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
