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
#include <stdexcept>

/**
 * @brief Constructor de PlanificacionEmpleados.
 * Inicializa el algoritmo con la instancia del problema y el resolvedor de casos pequeños.
 * @param inst Instancia inicial del problema de planificación.
 * @param small_solver Estrategia para resolver el caso base.
 */
PlanificacionEmpleados::PlanificacionEmpleados(Instancia* inst, SmallSolver* small_solver)
    : DivideYVenceras(inst), small_solver_(small_solver) {
  instancia_empleados_ = dynamic_cast<InstanciaEmpleados*>(inst);
  if (instancia_empleados_ == nullptr) {
    throw std::invalid_argument("Error: la instancia no es de tipo InstanciaEmpleados");
  }
  if (small_solver_ == nullptr) {
    throw std::invalid_argument("Error: small_solver no puede ser nullptr");
  }
  solucion_problema_ = new SolucionEmpleados(
    instancia_empleados_->GetNumEmpleados(),
    instancia_empleados_->GetNumDias(),
    0, 0
  );
}

PlanificacionEmpleados::~PlanificacionEmpleados() {
  delete small_solver_;
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

std::vector<int> PlanificacionEmpleados::CalcularFreeDays(InstanciaEmpleados* inst_emp, 
                                                          int dias_subinstancia, int dias_total) const {
  int num_emp = inst_emp->GetNumEmpleados();
  std::vector<int> free_days(num_emp, 0);
  for (int e = 0; e < num_emp; ++e) {
    int descansos = inst_emp->GetDiasDescanso(e);
    free_days[e] = (descansos * dias_subinstancia) / dias_total;
  }
  return free_days;
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
  int dias_izq   = dias_total / 2;
  std::vector<int> free_izq = CalcularFreeDays(inst_emp, dias_izq, dias_total);
  std::vector<int> free_der = CalcularFreeDays(inst_emp, dias_total - dias_izq, dias_total);
  for (int e = 0; e < inst_emp->GetNumEmpleados(); ++e) {
    free_der[e] = inst_emp->GetDiasDescanso(e) - free_izq[e];
  }
  return {
    inst_emp->SubInstancia(0,        dias_izq,   free_izq),
    inst_emp->SubInstancia(dias_izq, dias_total, free_der)
  };
}

/**
 * @brief Resuelve el caso base delegando en la estrategia inyectada.
 * @param inst Instancia de 1 día a resolver.
 * @return Solución para ese día.
 */
Solucion* PlanificacionEmpleados::SolveSmall(Instancia* inst) {
  return small_solver_->ResolverDiaPequeño(inst);
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
  int descansos_necesarios = instancia_empleados_->GetDiasDescanso(e);
  int descansos_reales = 0;
  for (int d = 0; d < sol->GetNumDias(); ++d) {
    if (sol->GetAsignacion(e, d) == -1) descansos_reales++;
  }
  if (descansos_reales > descansos_necesarios) {
    AsignarDescansosSobrantes(sol, e);
  } else if (descansos_reales < descansos_necesarios) {
    QuitarDescansosFaltantes(sol, e);
  }
}

/**
 * @brief Asigna trabajo a un empleado que tiene más descansos de los necesarios.
 * Prioriza turnos sin cubrir con mayor satisfacción. Si todos están cubiertos,
 * asigna al de mayor satisfacción.
 * @param sol Solución combinada a ajustar.
 * @param e Índice del empleado a ajustar.
 */
void PlanificacionEmpleados::AsignarDescansosSobrantes(SolucionEmpleados* sol, int e) {
  int dias_total           = sol->GetNumDias();
  int num_emp              = sol->GetNumEmpleados();
  int num_turnos           = instancia_empleados_->GetNumTurnos();
  int descansos_necesarios = instancia_empleados_->GetDiasDescanso(e);
  int descansos_reales     = 0;
  for (int d = 0; d < dias_total; ++d) {
    if (sol->GetAsignacion(e, d) == -1) descansos_reales++;
  }
  while (descansos_reales > descansos_necesarios) {
    int mejor_dia              = -1;
    int mejor_t                = -1;
    int mejor_sat              = std::numeric_limits<int>::min();
    bool encontrado_sin_cubrir = false;
    for (int d = 0; d < dias_total; ++d) {
      if (sol->GetAsignacion(e, d) != -1) continue;
      for (int t = 0; t < num_turnos; ++t) {
        int asignados = 0;
        for (int ee = 0; ee < num_emp; ++ee) {
          if (sol->GetAsignacion(ee, d) == t) asignados++;
        }
        bool sin_cubrir = asignados < instancia_empleados_->GetMinTurnos(d, t);
        int sat = instancia_empleados_->GetSatisfaccion(e, d, t);
        if (sin_cubrir && (!encontrado_sin_cubrir || sat > mejor_sat)) {
          encontrado_sin_cubrir = true;
          mejor_sat = sat;
          mejor_dia = d;
          mejor_t   = t;
        }
        if (!encontrado_sin_cubrir && sat > mejor_sat) {
          mejor_sat = sat;
          mejor_dia = d;
          mejor_t   = t;
        }
      }
    }
    if (mejor_dia != -1) {
      sol->SetAsignacion(e, mejor_dia, mejor_t);
    }
    descansos_reales--;
  }
}

/**
 * @brief Quita trabajo a un empleado que tiene menos descansos de los necesarios.
 * Prioriza quitar del turno con mayor superávit. Si no hay superávit, quita del
 * turno de menor satisfacción que no rompa cobertura. Como último recurso quita
 * del de menor satisfacción sin restricción.
 * @param sol Solución combinada a ajustar.
 * @param e Índice del empleado a ajustar.
 */
void PlanificacionEmpleados::QuitarDescansosFaltantes(SolucionEmpleados* sol, int e) {
  int dias_total           = sol->GetNumDias();
  int num_emp              = sol->GetNumEmpleados();
  int descansos_necesarios = instancia_empleados_->GetDiasDescanso(e);
  int descansos_reales     = 0;
  for (int d = 0; d < dias_total; ++d) {
    if (sol->GetAsignacion(e, d) == -1) descansos_reales++;
  }
  while (descansos_reales < descansos_necesarios) {
    int peor_dia        = -1;
    int mayor_superavit = -1;
    for (int d = 0; d < dias_total; ++d) {
      int t = sol->GetAsignacion(e, d);
      if (t == -1) continue;
      int asignados = 0;
      for (int ee = 0; ee < num_emp; ++ee) {
        if (sol->GetAsignacion(ee, d) == t) asignados++;
      }
      int superavit = asignados - instancia_empleados_->GetMinTurnos(d, t);
      if (superavit > mayor_superavit) {
        mayor_superavit = superavit;
        peor_dia        = d;
      }
    }
    if (mayor_superavit <= 0) {
      int peor_sat = std::numeric_limits<int>::max();
      for (int d = 0; d < dias_total; ++d) {
        int t = sol->GetAsignacion(e, d);
        if (t == -1) continue;
        int asignados = 0;
        for (int ee = 0; ee < num_emp; ++ee) {
          if (sol->GetAsignacion(ee, d) == t) asignados++;
        }
        bool rompe_cobertura = asignados <= instancia_empleados_->GetMinTurnos(d, t);
        int sat = instancia_empleados_->GetSatisfaccion(e, d, t);
        if (!rompe_cobertura && sat < peor_sat) {
          peor_sat = sat;
          peor_dia = d;
        }
      }
      if (peor_dia == -1) {
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