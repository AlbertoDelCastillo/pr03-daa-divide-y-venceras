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
 * @file configuracion-algoritmo.cc
 * @brief Implementación de la clase ConfiguracionAlgoritmo para gestionar
 *        parámetros de configuración del algoritmo mediante pares clave-valor.
 * @date Mar 14 2026
 * @version 1.0
 */

#include "configuracion-algoritmo.h"

/**
 * @brief Constructor por defecto.
 *
 * Inicializa el contenedor interno de configuraciones vacío.
 */
ConfiguracionAlgoritmo::ConfiguracionAlgoritmo() : configuraciones_() {}

/**
 * @brief Añade una configuración al contenedor.
 * @param clave Clave identificadora de la configuración.
 * @param valor Valor asociado a la clave.
 * @throws std::invalid_argument Si la clave ya existe.
 */
void ConfiguracionAlgoritmo::AñadirConfiguracion(const std::string& clave,
    const std::string& valor) {
  auto claveIncluida = configuraciones_.find(clave);
  if (claveIncluida != configuraciones_.end()) {
    throw std::invalid_argument("La clave '" + clave + "' ya existe en la configuracion");
  }
  configuraciones_.emplace(clave, valor);
}

/**
 * @brief Obtiene el valor asociado a una clave.
 * @param clave Clave de la configuración a consultar.
 * @return Valor asociado a la clave solicitada.
 * @throws std::out_of_range Si la clave no existe.
 */
std::string ConfiguracionAlgoritmo::ObtenerConfiguracion(const std::string& clave) const {
  auto claveDeseada = configuraciones_.find(clave);
  if (claveDeseada == configuraciones_.end()) {
    throw std::out_of_range("La clave " + clave + " no existe en la configuracion");
  }
  return claveDeseada->second;
}