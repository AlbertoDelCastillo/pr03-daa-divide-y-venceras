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
 * @brief Clase que representa la solución al problema de planificación de empleados.
 * @date Mar 9 2026
 * @version 1.0
 */

#ifndef SOLUCION_EMPLEADOS_H
#define SOLUCION_EMPLEADOS_H

#include <vector>
#include "solucion.h"

/**
 * @class SolucionEmpleados
 * @brief Representa una solución al problema de planificación de empleados.
 * Almacena la asignación X[e][d] donde -1 indica descanso, y el valor
 * de la función objetivo f(x) = suma_satisfaccion + turnos_cubiertos * 100.
 */
class SolucionEmpleados : public Solucion {
 public:
  SolucionEmpleados(int, int, int, int);
  void Mostrar() override;
  int GetAsignacion(int, int) const;
  void SetAsignacion(int, int, int);
  int GetValorObjetivo() const { return calidad_; }
  int GetNumDias() const { return num_dias_; }
  int GetNumEmpleados() const { return num_empleados_; }
  ~SolucionEmpleados() = default;

 private:
  int CalcularCalidad(int, int);
  std::vector<std::vector<int>> asignacion_;
  int calidad_;
  int num_empleados_;
  int num_dias_;
};

#endif