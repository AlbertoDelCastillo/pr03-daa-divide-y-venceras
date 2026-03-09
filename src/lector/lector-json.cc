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
    std::cerr << "Error: No se pudo abrir el archivo JSON en la ruta: " << ruta_fichero << std::endl;
    return nullptr; 
  }
  try {
    json datos_json;
    archivo >> datos_json;
    int dias = datos_json["numero_dias"];
    std::vector<std::string> empleados = datos_json["empleados"];
    std::vector<int> dias_descanso = datos_json["descansos_C"];
    std::vector<std::vector<int>> min_turnos = datos_json["minimos_turno_B"];
    std::vector<std::vector<std::vector<int>>> satisfaccion = datos_json["satisfaccion_A"];
    archivo.close();
    return new InstanciaEmpleados(empleados, dias, satisfaccion, min_turnos, dias_descanso);
  } catch (const json::exception& e) {
    std::cerr << "Error al parsear el archivo JSON: " << e.what() << std::endl;
    archivo.close();
    return nullptr;
  }
}