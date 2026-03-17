#include "combine-casa.h"

Solucion* CombineCasa::Combinar(Solucion*, Solucion*) {
  SolucionEmpleados* s1 = dynamic_cast<SolucionEmpleados*>(sol1);
  SolucionEmpleados* s2 = dynamic_cast<SolucionEmpleados*>(sol2);
  SolucionEmpleados* sol = PlanificacionEmpleados::ConcatenarSoluciones(s1, s2);
  for (int e = 0; e < sol->GetNumEmpleados(); ++e) {
    AjustarDescansos(sol, e);
  }
  auto [suma_sat, turnos_cub] = RecalcularCalidad(sol);
  sol->ActualizarCalidad(suma_sat, turnos_cub);
  return sol;
}
