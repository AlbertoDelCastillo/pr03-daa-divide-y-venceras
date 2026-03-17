#include "combine-modi.h"

#include <random>

void CombineModi::QuitarAsignacionAleatoria(SolucionEmpleados* sol) const {
  std::vector<int> empleados_con_asignacion;
  for (int e = 0; e < sol->GetNumEmpleados(); ++e) {
    for (int d = 0; d < sol->GetNumDias(); ++d) {
      if (sol->GetAsignacion(e, d) != -1) {
        empleados_con_asignacion.push_back(e);
        break;
      }
    }
  }
  if (empleados_con_asignacion.empty()) {
    return;
  }
  static std::mt19937 generador(std::random_device{}());
  std::uniform_int_distribution<int> distribucion_empleado(
      0, static_cast<int>(empleados_con_asignacion.size()) - 1);
  int empleado = empleados_con_asignacion[distribucion_empleado(generador)];
  std::vector<int> dias_asignados;
  for (int d = 0; d < sol->GetNumDias(); ++d) {
    if (sol->GetAsignacion(empleado, d) != -1) {
      dias_asignados.push_back(d);
    }
  }
  if (dias_asignados.empty()) {
    return;
  }
  std::uniform_int_distribution<int> distribucion_dia(
      0, static_cast<int>(dias_asignados.size()) - 1);
  int dia = dias_asignados[distribucion_dia(generador)];
  sol->SetAsignacion(empleado, dia, -1);
}

Solucion* CombineModi::Combinar(Solucion* sol1, Solucion* sol2) {
  SolucionEmpleados* s1 = dynamic_cast<SolucionEmpleados*>(sol1);
  SolucionEmpleados* s2 = dynamic_cast<SolucionEmpleados*>(sol2);
  SolucionEmpleados* sol = ConcatenarSoluciones(s1, s2);
  for (int e = 0; e < sol->GetNumEmpleados(); ++e) {
    AjustarDescansos(sol, e);
  }
  QuitarAsignacionAleatoria(sol);
  
  auto [suma_sat, turnos_cub] = RecalcularCalidad(sol);
  sol->ActualizarCalidad(suma_sat, turnos_cub);
  return sol;
}
