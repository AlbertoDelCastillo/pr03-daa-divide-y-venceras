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
 * @brief Implementación del algoritmo de planificación de empleados mediante Divide y Vencerás.
 * @date Mar 9 2026
 * @version 1.0
 */

#include "planificacion-empleados.h"
#include <limits>
#include <iostream>

/**
 * @brief Constructor de PlanificacionEmpleados.
 * Inicializa el algoritmo con la instancia del problema y guarda el puntero tipado.
 * @param inst Instancia inicial del problema de planificación.
 */
PlanificacionEmpleados::PlanificacionEmpleados(Instancia* inst) : DivideYVenceras(inst) {
  instancia_empleados_ = dynamic_cast<InstanciaEmpleados*>(inst);
  solucion_problema_ = new SolucionEmpleados(
    instancia_empleados_->GetNumEmpleados(),
    instancia_empleados_->GetNumDias(),
    0, 0
  );
}

/**
 * @brief Determina si la instancia es suficientemente pequeña para resolver directamente.
 * Caso base: instancia de 1 día.
 * @param inst Instancia a evaluar.
 * @return true si el número de días es <= 1, false en caso contrario.
 */
bool PlanificacionEmpleados::Small(Instancia* inst) {
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
  return inst_emp->GetNumDias() <= 1;
}

/**
 * @brief Divide la instancia en dos subinstancias por la mitad de días.
 * Los freeDays se reparten proporcionalmente: floor a la izquierda, el resto a la derecha.
 * @param inst Instancia a dividir.
 * @return Vector con dos subinstancias.
 */
std::vector<Instancia*> PlanificacionEmpleados::Divide(Instancia* inst) {
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
  int dias_total = inst_emp->GetNumDias();
  int dias_izq = dias_total / 2;
  std::vector<int> free_izq(inst_emp->GetNumEmpleados(), 0);
  std::vector<int> free_der(inst_emp->GetNumEmpleados(), 0);
  return {
    inst_emp->SubInstancia(0, dias_izq, free_izq),
    inst_emp->SubInstancia(dias_izq, dias_total, free_der)
  };
}

/**
 * @brief Resuelve el caso base de 1 día mediante un algoritmo voraz.
 * Fuerza el descanso de empleados con freeDays >= 1, luego asigna por máxima satisfacción turno a turno.
 * @param inst Instancia de 1 día a resolver.
 * @return Solución para ese día.
 */
Solucion* PlanificacionEmpleados::SolveSmall(Instancia* inst) {
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(inst);
  int num_emp = inst_emp->GetNumEmpleados();
  int num_turnos = inst_emp->GetNumTurnos();
  SolucionEmpleados* sol = new SolucionEmpleados(num_emp, 1, 0, 0);
  for (int t = 0; t < num_turnos; ++t) {
    int mejor_emp = -1;
    int mejor_sat = std::numeric_limits<int>::min();
    for (int e = 0; e < num_emp; ++e) {
      if (sol->GetAsignacion(e, 0) != -1) continue;
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

/**
 * @brief Concatena dos soluciones parciales en una nueva solución.
 * @param s1 Solución de la primera mitad.
 * @param s2 Solución de la segunda mitad.
 * @return Nueva solución con las dos matrices unidas.
 */
SolucionEmpleados* PlanificacionEmpleados::ConcatenarSoluciones(SolucionEmpleados* s1, SolucionEmpleados* s2) {
  int num_emp = s1->GetNumEmpleados();
  int dias1 = s1->GetNumDias();
  int dias2 = s2->GetNumDias();
  int dias_total = dias1 + dias2;
  SolucionEmpleados* sol = new SolucionEmpleados(num_emp, dias_total, 0, 0);
  for (int e = 0; e < num_emp; ++e) {
    for (int d = 0; d < dias1; ++d) {
      sol->SetAsignacion(e, d, s1->GetAsignacion(e, d));
    }
    for (int d = 0; d < dias2; ++d) {
      sol->SetAsignacion(e, dias1 + d, s2->GetAsignacion(e, d));
    }
  }
  return sol;
}

/**
 * @brief Ajusta los descansos de un empleado concreto en la solución combinada.
 * Si sobran descansos asigna el turno de mayor satisfacción en ese día libre.
 * Si faltan descansos quita la asignación de menor satisfacción.
 * @param sol Solución combinada a ajustar.
 * @param e Índice del empleado a ajustar.
 */
void PlanificacionEmpleados::AjustarDescansos(SolucionEmpleados* sol, int e) {
  int dias_total = sol->GetNumDias();
  int num_turnos = instancia_empleados_->GetNumTurnos();
  int descansos_necesarios = instancia_empleados_->GetDiasDescanso(e);
  int descansos_reales = 0;
  for (int d = 0; d < dias_total; ++d) {
    if (sol->GetAsignacion(e, d) == -1) descansos_reales++;
  }
  while (descansos_reales > descansos_necesarios) {
    int mejor_dia = -1;
    int mejor_sat = std::numeric_limits<int>::min();
    for (int d = 0; d < dias_total; ++d) {
      if (sol->GetAsignacion(e, d) != -1) continue;
      for (int t = 0; t < num_turnos; ++t) {
        int sat = instancia_empleados_->GetSatisfaccion(e, d, t);
        if (sat > mejor_sat) {
          mejor_sat = sat;
          mejor_dia = d;
        }
      }
    }
    if (mejor_dia != -1) {
      int mejor_t = -1;
      int sat_max = std::numeric_limits<int>::min();
      for (int t = 0; t < num_turnos; ++t) {
        int sat = instancia_empleados_->GetSatisfaccion(e, mejor_dia, t);
        if (sat > sat_max) { sat_max = sat; mejor_t = t; }
      }
      sol->SetAsignacion(e, mejor_dia, mejor_t);
    }
    descansos_reales--;
  }
  while (descansos_reales < descansos_necesarios) {
    int peor_dia = -1;
    int mayor_superavit = -1;
    for (int d = 0; d < dias_total; ++d) {
      int t = sol->GetAsignacion(e, d);
      if (t == -1) continue;
      int asignados = 0;
      for (int ee = 0; ee < sol->GetNumEmpleados(); ++ee) {
        if (sol->GetAsignacion(ee, d) == t) asignados++;
      }
      int superavit = asignados - instancia_empleados_->GetMinTurnos(d, t);
      if (superavit > mayor_superavit) {
        mayor_superavit = superavit;
        peor_dia = d;
      }
    }
    if (mayor_superavit <= 0) {
      int peor_sat = std::numeric_limits<int>::max();
      for (int d = 0; d < dias_total; ++d) {
        int t = sol->GetAsignacion(e, d);
        if (t == -1) continue;
        int sat = instancia_empleados_->GetSatisfaccion(e, d, t);
        if (sat < peor_sat) {
          peor_sat = sat;
          peor_dia = d;
        }
      }
    }
    if (peor_dia != -1) {
      sol->SetAsignacion(e, peor_dia, -1);
    }
    descansos_reales++;
  }
}

/**
 * @brief Recalcula la suma de satisfacción y los turnos cubiertos de la solución.
 * Actualiza la calidad interna de la solución combinada.
 * @param sol Solución a recalcular.
 */
std::pair<int,int> PlanificacionEmpleados::RecalcularCalidad(SolucionEmpleados* sol) {
  int num_emp = sol->GetNumEmpleados();
  int dias_total = sol->GetNumDias();
  int num_turnos = instancia_empleados_->GetNumTurnos();
  int suma_sat = 0;
  int turnos_cub = 0;
  for (int d = 0; d < dias_total; ++d) {
    for (int e = 0; e < num_emp; ++e) {
      int t = sol->GetAsignacion(e, d);
      if (t != -1) {
        suma_sat += instancia_empleados_->GetSatisfaccion(e, d, t);
      }
    }
    for (int t = 0; t < num_turnos; ++t) {
      int asignados = 0;
      for (int e = 0; e < num_emp; ++e) {
        if (sol->GetAsignacion(e, d) == t) asignados++;
      }
      if (asignados >= instancia_empleados_->GetMinTurnos(d, t)) {
        turnos_cub++;
      }
    }
  }
  return {suma_sat, turnos_cub};
}
/**
 * @brief Combina dos soluciones parciales en una solución global.
 * @param sol1 Solución de la primera mitad.
 * @param sol2 Solución de la segunda mitad.
 * @return Solución combinada con calidad recalculada.
 */
Solucion* PlanificacionEmpleados::Combine(Solucion* sol1, Solucion* sol2) {
  SolucionEmpleados* s1 = dynamic_cast<SolucionEmpleados*>(sol1);
  SolucionEmpleados* s2 = dynamic_cast<SolucionEmpleados*>(sol2);
  SolucionEmpleados* sol = ConcatenarSoluciones(s1, s2);
  for (int e = 0; e < sol->GetNumEmpleados(); ++e) {
    AjustarDescansos(sol, e);
  }
  auto [suma_sat, turnos_cub] = RecalcularCalidad(sol);
  sol->ActualizarCalidad(suma_sat, turnos_cub);
  return sol;
}

/**
 * @brief Muestra la cobertura de turnos por día comparando asignados vs mínimo requerido.
 * @param sol Solución final.
 * @param inst Instancia del problema.
 */
void PlanificacionEmpleados::MostrarCobertura(Solucion* sol, InstanciaEmpleados* inst) const {
  SolucionEmpleados* s = dynamic_cast<SolucionEmpleados*>(sol);
  int num_turnos = inst->GetNumTurnos();
  std::cout << "\n=== Cobertura de Turnos ===" << std::endl;
  for (int d = 0; d < inst->GetNumDias(); ++d) {
    std::cout << "Dia " << d << ":" << std::endl;
    for (int t = 0; t < num_turnos; ++t) {
      int asignados = 0;
      for (int e = 0; e < inst->GetNumEmpleados(); ++e) {
        if (s->GetAsignacion(e, d) == t) asignados++;
      }
      int requeridos = inst->GetMinTurnos(d, t);
      std::cout << "  T" << t << ": " << asignados << "/" << requeridos
                << (asignados >= requeridos ? " OK" : " INSUFICIENTE") << std::endl;
    }
  }
}