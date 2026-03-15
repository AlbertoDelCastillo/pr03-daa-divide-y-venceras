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
 * @brief Clase que implementa el algoritmo de planificación de empleados mediante Divide y Vencerás.
 * @date Mar 9 2026
 * @version 1.0
 */

#ifndef PLANIFICACION_EMPLEADOS_H
#define PLANIFICACION_EMPLEADOS_H

#include <vector>
#include "divideyvenceras.h"
#include "instancia-empleados.h"
#include "solucion-empleados.h"
#include "small-solver/small-solver.h"

/**
 * @class PlanificacionEmpleados
 * @brief Implementa el algoritmo de planificación de empleados usando el patrón Divide y Vencerás.
 * Hereda de DivideYVenceras e implementa los 4 métodos virtuales: Small, SolveSmall, Divide y Combine.
 * El caso base se resuelve mediante un algoritmo voraz para 1 día.
 */
class PlanificacionEmpleados : public DivideYVenceras {
 public:
  PlanificacionEmpleados(Instancia*, SmallSolver*);
  ~PlanificacionEmpleados();
  void MostrarCobertura(Solucion*, InstanciaEmpleados*) const;

 private:
  SolucionEmpleados* ConcatenarSoluciones(SolucionEmpleados*, SolucionEmpleados*);
  std::vector<int> CalcularFreeDays(InstanciaEmpleados*, int, int) const;
  void AjustarDescansos(SolucionEmpleados*, int);
  std::vector<int> OrdenarTurnosPorDificultad(InstanciaEmpleados*, const std::vector<bool>&) const;
  std::pair<int,int> RecalcularCalidad(SolucionEmpleados*);
  InstanciaEmpleados* instancia_empleados_;
  SmallSolver* small_solver_;
  bool Small(Instancia*) override;
  Solucion* SolveSmall(Instancia*) override;
  std::vector<Instancia*> Divide(Instancia*) override;
  Solucion* Combine(Solucion*, Solucion*) override;
};

#endif