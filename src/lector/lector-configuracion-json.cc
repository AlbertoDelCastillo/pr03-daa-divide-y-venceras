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
 * @file lector-configuracion-json.cc
 * @brief Implementación de LectorConfiguracionJSON para leer la configuración
 *        del algoritmo desde un fichero JSON.
 * @date Mar 15 2026
 * @version 1.0
 */

#include "lector-configuracion-json.h"
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

/**
 * @brief Lee un fichero JSON y construye un objeto ConfiguracionAlgoritmo.
 *
 * Extrae las claves "class" y "smallSolver.class" del JSON y las añade
 * a la configuración como "class" y "smallSolver" respectivamente.
 *
 * @param ruta Ruta al fichero JSON de configuración.
 * @return ConfiguracionAlgoritmo con los parámetros leídos, o vacía si
 *         el fichero no pudo abrirse.
 */
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