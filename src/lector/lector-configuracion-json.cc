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

/**
 * @brief Desciende recursivamente por nodos anidados de "smallSolver" hasta
 *        encontrar el nodo hoja (sin clave "smallSolver") y devuelve su "class".
 *
 * @param nodo Nodo JSON a inspeccionar.
 * @return Valor de "class" del nodo hoja.
 * @throws std::invalid_argument Si cualquier nodo del recorrido carece de "class".
 */
std::string LectorConfiguracionJSON::ExtraerClaseHoja(const nlohmann::json& nodo) {
    if (!nodo.contains("class")) {
        throw std::invalid_argument("Error: nodo de configuración sin clave \"class\"");
    }
    if (nodo.contains("smallSolver")) {
        return ExtraerClaseHoja(nodo["smallSolver"]);
    }
    return nodo["class"];
}

/**
 * @brief Lee un fichero JSON y construye un objeto ConfiguracionAlgoritmo.
 *
 * Extrae la clave "class" del nodo raíz y, si existe "smallSolver", desciende
 * recursivamente hasta el nodo hoja para obtener la clase del solver base.
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
    if (json.contains("smallSolver")) {
        config.AñadirConfiguracion("smallSolver", ExtraerClaseHoja(json["smallSolver"]));
    }
    return config;
}