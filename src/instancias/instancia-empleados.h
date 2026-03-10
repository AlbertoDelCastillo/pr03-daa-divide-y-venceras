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
 * @file instancia-empleados.h
 * @brief Declaración de la clase InstanciaEmpleados para representar instancias
 *        del problema de planificación de turnos de empleados.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef INSTANCIAS_EMPLEADOS_H
#define INSTANCIAS_EMPLEADOS_H

#include <vector>
#include <string>
#include <iostream>
#include "instancia.h"

/**
 * @class InstanciaEmpleados
 * @brief Representa una instancia del problema de planificación de empleados.
 *        Almacena información sobre empleados, días, satisfacción, mínimos por turno y descansos.
 */
class InstanciaEmpleados : public Instancia {
 public:
  InstanciaEmpleados(const std::vector<std::string>&, int, const std::vector<std::vector<std::vector<int>>>&,
                     const std::vector<std::vector<int>>&, const std::vector<int>&);
  ~InstanciaEmpleados() = default;
  InstanciaEmpleados* SubInstancia(int, int, const std::vector<int>&) const;
  void Mostrar() override;
  int GetNumEmpleados() const;
  int GetNumTurnos() const;
  int GetNumDias() const;
  std::string GetNombreEmpleado(int) const;
  int GetSatisfaccion(int, int, int) const;
  int GetMinTurnos(int, int) const;
  int GetDiasDescanso(int) const;  
  
 private:
  std::vector<std::string> empleados_;
  int dias_;
  std::vector<std::vector<std::vector<int>>> satisfaccion_;
  std::vector<std::vector<int>> min_turnos_;
  std::vector<int> dias_descanso_;
};

#endif