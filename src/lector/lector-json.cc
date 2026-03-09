#include "lector-json.h"

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

// Usamos un alias para no escribir nlohmann::json
using json = nlohmann::json;

/**
 * @brief Lee un fichero JSON y construye una InstanciaEmpleados.
 */
Instancia* LectorJSON::LeerDesdeFichero(const std::string& ruta_fichero) {
  std::ifstream archivo(ruta_fichero);
  if (!archivo.is_open()) {
    std::cerr << "Error: No se pudo abrir el archivo JSON: " << ruta_fichero << std::endl;
    return nullptr; 
  }
  try {
    json datos;
    archivo >> datos;
    archivo.close();
    int dias = datos["planningHorizon"];
    int num_empleados = datos["employees"].size();
    int num_turnos = datos["shifts"].size();
    std::vector<std::string> empleados;
    std::vector<int> dias_descanso;
    for (const auto& emp : datos["employees"]) {
      empleados.push_back(emp["name"]);
      dias_descanso.push_back(emp["freeDays"]);
    }
    std::vector<std::vector<std::vector<int>>> satisfaccion(
        num_empleados, std::vector<std::vector<int>>(
            dias, std::vector<int>(num_turnos, 0)));
    std::vector<std::vector<int>> min_turnos(
        dias, std::vector<int>(num_turnos, 0));
    for (const auto& sat : datos["satisfaction"]) {
      int e = sat["employee"];
      int d = sat["day"];
      int t = sat["shift"];
      int valor = sat["value"];
      satisfaccion[e][d][t] = valor;
    }
    for (const auto& req : datos["requiredEmployees"]) {
      int d = req["day"];
      int t = req["shift"];
      int valor = req["value"];
      min_turnos[d][t] = valor;
    }
    return new InstanciaEmpleados(empleados, dias, satisfaccion, min_turnos, dias_descanso);
  } catch (const json::exception& e) {
    std::cerr << "Error al parsear la estructura del JSON: " << e.what() << std::endl;
    return nullptr;
  }
}