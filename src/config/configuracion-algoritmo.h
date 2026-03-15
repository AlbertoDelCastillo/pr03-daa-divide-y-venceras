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
* @file configuracion-algoritmo.h
* @brief Declaración de la clase ConfiguracionAlgoritmo para almacenar
* pares clave-valor con parámetros de configuración del algoritmo.
* @date Mar 14 2026
* @version 1.0
*/

#ifndef CONFIGURACION_ALGORITMO_H
#define CONFIGURACION_ALGORITMO_H

#include <map>
#include <string>
#include <stdexcept>

/**
 * @class ConfiguracionAlgoritmo
 * @brief Contenedor de parámetros de configuración del algoritmo.
 *
 * Almacena pares clave-valor de tipo string. Garantiza que no existan
 * claves duplicadas lanzando una excepción si se intenta insertar una
 * clave ya presente.
 */
class ConfiguracionAlgoritmo {
 public:
  ConfiguracionAlgoritmo();
  void AñadirConfiguracion(const std::string& clave, const std::string& valor);
  std::string ObtenerConfiguracion(const std::string& clave) const;
  
 private:
  std::map<std::string, std::string> configuraciones_;
};

#endif