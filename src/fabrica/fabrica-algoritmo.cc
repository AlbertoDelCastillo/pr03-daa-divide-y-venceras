#include "fabrica-algoritmo.h"

Algoritmo* FabricaAlgoritmos::CrearAlgoritmo(ConfiguracionAlgoritmo& config, Instancia* datos) {
  std::string small_solver = config.ObtenerConfiguracion("smallSolver");
  SmallSolver* motor_pequeño = nullptr;
  if (small_solver == "Greedy") {
    motor_pequeño = new SolverGready();
  } else if (small_solver == "PD") {
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