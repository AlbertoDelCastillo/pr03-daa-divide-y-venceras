#ifndef INSTANCIAS_EMPLEADOS_H
#define INSTANCIAS_EMPLEADOS_H

#include <vector>
#include <string>
#include <iostream>
#include "instancia.h"

/**
 * @enum Turno
 * @brief Enumeración para representar los turnos de trabajo posibles.
 */
enum class Turno { 
  MANANA = 0, 
  TARDE = 1, 
  NOCHE = 2 
};

/**
 * @class InstanciaEmpleados
 * @brief Representa una instancia del problema de planificación de empleados.
 *        Almacena información sobre empleados, días, satisfacción, mínimos por turno y descansos.
 */
class InstanciaEmpleados : public Instancia {
 public:
  /**
   * @brief Constructor de InstanciaEmpleados.
   * @param empleados Vector con los nombres de los empleados.
   * @param dias Número de días a planificar.
   * @param satisfaccion Matriz tridimensional con la satisfacción de cada empleado por día y turno.
   * @param min_turnos Matriz bidimensional con el mínimo de empleados requeridos por día y turno.
   * @param dias_descanso Vector con los días de descanso requeridos por cada empleado.
   */
  InstanciaEmpleados(const std::vector<std::string>& empleados, 
                     int dias, 
                     const std::vector<std::vector<std::vector<int>>>& satisfaccion,
                     const std::vector<std::vector<int>>& min_turnos,
                     const std::vector<int>& dias_descanso);

  /**
   * @brief Destructor por defecto.
   */
  ~InstanciaEmpleados() = default;

  /**
   * @brief Muestra por pantalla un resumen de la instancia de empleados.
   *        Incluye número de días, empleados y sus descansos requeridos.
   */
  void Mostrar() override;

  /**
   * @brief Obtiene el número total de empleados.
   * @return Número de empleados.
   */
  int GetNumEmpleados() const;

  /**
   * @brief Obtiene el número total de días a planificar.
   * @return Número de días.
   */
  int GetNumDias() const;

  /**
   * @brief Obtiene el nombre de un empleado dado su índice.
   * @param indice_empleado Índice del empleado.
   * @return Nombre del empleado.
   */
  std::string GetNombreEmpleado(int indice_empleado) const;
  
  /**
   * @brief Obtiene la satisfacción de un empleado en un día y turno concreto.
   * @param indice_empleado Índice del empleado.
   * @param dia Día a consultar.
   * @param turno Turno a consultar.
   * @return Valor de satisfacción.
   */
  int GetSatisfaccion(int indice_empleado, int dia, Turno turno) const;

  /**
   * @brief Obtiene el mínimo de empleados requeridos para un día y turno concreto.
   * @param dia Día a consultar.
   * @param turno Turno a consultar.
   * @return Mínimo de empleados requeridos.
   */
  int GetMinTurnos(int dia, Turno turno) const;

  /**
   * @brief Obtiene los días de descanso requeridos por un empleado.
   * @param indice_empleado Índice del empleado.
   * @return Número de días de descanso requeridos.
   */
  int GetDiasDescanso(int indice_empleado) const;  
  
 private:
  std::vector<std::string> empleados_; ///< Nombres de los empleados.
  int dias_; ///< Número de días a planificar.
  std::vector<std::vector<std::vector<int>>> satisfaccion_; ///< Satisfacción por empleado, día y turno.
  std::vector<std::vector<int>> min_turnos_; ///< Mínimo de empleados por día y turno.
  std::vector<int> dias_descanso_; ///< Días de descanso requeridos por empleado.
};

#endif