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
 * @brief Implementación de la clase SolucionEmpleados.
 * @date Mar 9 2026
 * @version 1.0
 */

#include "solucion-empleados.h"
#include <iostream>
#include <iomanip>

/**
 * @brief Constructor de SolucionEmpleados.
 * Inicializa la matriz de asignación con todos los empleados en descanso
 * y calcula el valor de la función objetivo.
 * @param num_empleados Número de empleados.
 * @param num_dias Número de días.
 * @param suma_satisfaccion Suma de satisfacciones de la planificación.
 * @param turnos_cubiertos Número de turnos que cumplen el mínimo requerido.
 */
SolucionEmpleados::SolucionEmpleados(int num_empleados, int num_dias, int suma_satisfaccion, int turnos_cubiertos)
    : num_empleados_(num_empleados), num_dias_(num_dias) {
  calidad_ = CalcularCalidad(suma_satisfaccion, turnos_cubiertos);
  asignacion_.assign(num_empleados, std::vector<int>(num_dias, -1));
}

/**
 * @brief Calcula el valor de la función objetivo.
 * 
 * @param suma_satisfaccion Suma de satisfacciones de la planificación.
 * @param turnos_cubiertos Número de turnos que cumplen el mínimo requerido.
 * @return f(x) = suma_satisfaccion + turnos_cubiertos * 100.
 */
int SolucionEmpleados::CalcularCalidad(int suma_satisfaccion, int turnos_cubiertos) {
  return suma_satisfaccion + (turnos_cubiertos * 100);
}

/**
 * @brief Muestra la solución en formato de tabla legible.
 * Filas = empleados, columnas = días, valor = turno asignado o DESC si descansa.
 */
void SolucionEmpleados::Mostrar() {
  std::cout << std::setw(12) << " ";
  for (int d = 0; d < num_dias_; d++) {
    std::cout << std::setw(8) << "Día " + std::to_string(d);
  }
  std::cout << std::endl;
  for (int e = 0; e < num_empleados_; e++) {
    std::cout << std::setw(12) << "Empleado " + std::to_string(e);
    for (int d = 0; d < num_dias_; d++) {
      if (asignacion_[e][d] == -1) {
        std::cout << std::setw(8) << "DESC";
      } else {
        std::cout << std::setw(8) << "T" + std::to_string(asignacion_[e][d]);
      }
    }
    std::cout << std::endl;
  }
  std::cout << "Calidad: " << calidad_ << std::endl;
}

/**
 * @brief Obtiene el turno asignado a un empleado en un día concreto.
 * @return Índice del turno asignado, o -1 si es día de descanso.
 */
int SolucionEmpleados::GetAsignacion(int empleado, int dia) const {
  return asignacion_[empleado][dia];
}

/**
 * @brief Establece el turno asignado a un empleado en un día concreto.
 */
void SolucionEmpleados::SetAsignacion(int empleado, int dia, int turno) {
  asignacion_[empleado][dia] = turno;
}