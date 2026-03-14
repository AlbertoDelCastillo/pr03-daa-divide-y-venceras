#include "solver-pd.h"

Solucion* SolverPD::ResolverDiaPequeño(Instancia* inst) {
	InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
	if (inst_emp == nullptr) {
		throw std::invalid_argument("Error: la instancia no es de tipo InstanciaEmpleados");
	}
	int num_emp = inst_emp->GetNumEmpleados();
	int num_turnos = inst_emp->GetNumTurnos();
	SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
	std::vector<std::vector<int>> dp(
			num_emp + 1, std::vector<int>(num_turnos + 1, 0));
	std::vector<std::vector<bool>> asignado(
			num_emp + 1, std::vector<bool>(num_turnos + 1, false));
	for (int e = 1; e <= num_emp; ++e) {
		for (int k = 1; k <= num_turnos; ++k) {
			int sat_no_asignar = dp[e - 1][k];
			int sat_asignar = dp[e - 1][k - 1] +
					inst_emp->GetSatisfaccion(e - 1, 0, k - 1);
			if (sat_asignar > sat_no_asignar) {
				dp[e][k] = sat_asignar;
				asignado[e][k] = true;
			} else {
				dp[e][k] = sat_no_asignar;
			}
		}
	}
	int k_actual = num_turnos;
	for (int e = num_emp; e > 0 && k_actual > 0; --e) {
		if (asignado[e][k_actual]) {
			sol->SetAsignacion(e - 1, 0, k_actual - 1);
			--k_actual;
		}
	}
	return sol;
}
