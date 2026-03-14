#include "lector-configuracion-json.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

ConfiguracionAlgoritmo LectorConfiguracionJSON::LeerFichero(const std::string& ruta) {
    ConfiguracionAlgoritmo config;
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo de configuración en: " << ruta << std::endl;
        return config;
    }
    nlohmann::json json;
    archivo >> json;
    if (json.contains("class")) {
        config.AñadirConfiguracion("class", json["class"]);
    }
    if (json.contains("smallSolver") && json["smallSolver"].contains("class")) {
        config.AñadirConfiguracion("smallSolver", json["smallSolver"]["class"]);
    }
    return config;
}