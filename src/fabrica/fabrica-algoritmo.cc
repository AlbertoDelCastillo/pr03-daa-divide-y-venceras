/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 3: Divide y Vencerás - Planificación de Empleados
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @file fabrica-algoritmo.cc
 * @brief Implementación de la clase FabricaAlgoritmos para construir
 * @date Mar 15 2026
 * @version 1.0
*/

#include "fabrica-algoritmo.h"

/**
 * @brief Crea el algoritmo configurado para resolver la instancia.
 * Construye primero el motor para casos pequeños según la clave smallSolver
 * y después crea el algoritmo principal según la clave class.
 * @param config Configuración con las claves del algoritmo.
 * @param datos Instancia del problema a resolver.
 * @return Puntero al algoritmo creado, o nullptr si la clase principal
 * @throws std::invalid_argument Si el small solver no es reconocido.
 */
Algoritmo* FabricaAlgoritmos::CrearAlgoritmo(ConfiguracionAlgoritmo& config, Instancia* datos) {
  std::string small_solver = config.ObtenerConfiguracion("smallSolver");
  SmallSolver* motor_pequeño = nullptr;
  if (small_solver == "Greedy") {
    motor_pequeño = new SolverGready();
  } else if (small_solver == "DynamicProgramming") {
    motor_pequeño = new SolverPD();
  } else {
    throw std::invalid_argument("Error, motor pequeño no reconocido");
  }
  std::string tipo_algoritmo = config.ObtenerConfiguracion("class");
  Algoritmo* algoritmo_final = nullptr;
  if (tipo_algoritmo == "BinaryDivideAndConquer") {
    algoritmo_final = new PlanificacionEmpleados(datos, motor_pequeño);
  } else {
    std::cout << "Error: Algoritmo principal no reconocido (" << tipo_algoritmo << ")\n";
    delete motor_pequeño;
    return nullptr;
  }
  return algoritmo_final;
}