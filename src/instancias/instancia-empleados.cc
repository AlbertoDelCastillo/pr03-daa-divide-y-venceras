#include "instancia-empleados.h"

/**
 * @brief Constructor que inicializa todos los atributos de la instancia de empleados.
 * @param empleados Vector con los nombres de los empleados.
 * @param dias Número de días a planificar.
 * @param satisfaccion Matriz tridimensional con la satisfacción de cada empleado por día y turno.
 * @param min_turnos Matriz bidimensional con el mínimo de empleados requeridos por día y turno.
 * @param dias_descanso Vector con los días de descanso requeridos por cada empleado.
 */
InstanciaEmpleados::InstanciaEmpleados(const std::vector<std::string>& empleados, 
                    int dias, 
                    const std::vector<std::vector<std::vector<int>>>& satisfaccion,
                    const std::vector<std::vector<int>>& min_turnos,
                    const std::vector<int>& dias_descanso): 
      empleados_(empleados), 
      dias_(dias), 
      satisfaccion_(satisfaccion), 
      min_turnos_(min_turnos), 
      dias_descanso_(dias_descanso) {}


      /**
 * @brief Crea una subinstancia con un rango de días y freeDays personalizados.
 * @param dia_inicio Día de inicio del rango (inclusivo).
 * @param dia_fin Día de fin del rango (exclusivo).
 * @param free_days FreeDays de cada empleado para esta subinstancia.
 * @return Puntero a la nueva subinstancia.
 */
InstanciaEmpleados* InstanciaEmpleados::SubInstancia(int dia_inicio, int dia_fin, const std::vector<int>& free_days) const {
  int num_dias = dia_fin - dia_inicio;
  int num_emp = GetNumEmpleados();
  int num_turnos = GetNumTurnos();
  std::vector<std::vector<std::vector<int>>> sat_sub(
    num_emp, std::vector<std::vector<int>>(num_dias, std::vector<int>(num_turnos, 0)));
  std::vector<std::vector<int>> min_sub(num_dias, std::vector<int>(num_turnos, 0));
  for (int e = 0; e < num_emp; ++e) {
    for (int d = 0; d < num_dias; ++d) {
      for (int t = 0; t < num_turnos; ++t) {
        sat_sub[e][d][t] = satisfaccion_[e][dia_inicio + d][t];
      }
    }
  }
  for (int d = 0; d < num_dias; ++d) {
    for (int t = 0; t < num_turnos; ++t) {
      min_sub[d][t] = min_turnos_[dia_inicio + d][t];
    }
  }
  return new InstanciaEmpleados(empleados_, num_dias, sat_sub, min_sub, free_days);
}

/**
 * @brief Muestra por pantalla un resumen de la instancia de empleados.
 * Incluye número de días, empleados y sus descansos requeridos.
 */
void InstanciaEmpleados::Mostrar() {
  std::cout << "\n=== Resumen de la Instancia de Empleados ===" << std::endl;
  std::cout << "Numero de dias a planificar: " << dias_ << std::endl;
  std::cout << "Numero de empleados disponibles: " << GetNumEmpleados() << std::endl;
  
  std::cout << "\nListado de empleados y descansos requeridos:" << std::endl;
  for (int i = 0; i < GetNumEmpleados(); ++i) {
    std::cout << "  ID " << i << ": " << empleados_[i] 
              << " (Requiere " << dias_descanso_[i] << " dias libres)" << std::endl;
  }
  std::cout << "===========================================\n" << std::endl;
}

/**
 * @brief Obtiene el número total de empleados.
 * @return Número de empleados.
 */
int InstanciaEmpleados::GetNumEmpleados() const {
  return empleados_.size();
}

/**
 * @brief Obtiene el número total de días a planificar.
 * @return Número de días.
 */
int InstanciaEmpleados::GetNumDias() const {
  return dias_;
}

/**
 * @brief Obtiene el nombre de un empleado dado su índice.
 * @param indice_empleado Índice del empleado.
 * @return Nombre del empleado.
 */
std::string InstanciaEmpleados::GetNombreEmpleado(int indice_empleado) const {
  return empleados_[indice_empleado];
}

/**
 * @brief Obtiene el número de turnos disponibles.
 * @return Número de turnos.
 */
int InstanciaEmpleados::GetNumTurnos() const {
  return min_turnos_[0].size();
}


/**
 * @brief Obtiene la satisfacción de un empleado en un día y turno concreto.
 * @param indice_empleado Índice del empleado.
 * @param dia Día a consultar.
 * @param turno Turno a consultar.
 * @return Valor de satisfacción.
 */
int InstanciaEmpleados::GetSatisfaccion(int indice_empleado, int dia, int turno) const {
  return satisfaccion_[indice_empleado][dia][turno];
}

/**
 * @brief Obtiene el mínimo de empleados requeridos para un día y turno concreto.
 * @param dia Día a consultar.
 * @param turno Turno a consultar.
 * @return Mínimo de empleados requeridos.
 */
int InstanciaEmpleados::GetMinTurnos(int dia, int turno) const {
  return min_turnos_[dia][turno];
}

/**
 * @brief Obtiene los días de descanso requeridos por un empleado.
 * @param indice_empleado Índice del empleado.
 * @return Número de días de descanso requeridos.
 */
int InstanciaEmpleados::GetDiasDescanso(int indice_empleado) const {
  return dias_descanso_[indice_empleado];
}