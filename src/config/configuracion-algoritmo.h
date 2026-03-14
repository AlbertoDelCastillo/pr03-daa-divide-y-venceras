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
 * Clase container que almacena la configuracion del algoritmo
 */
class ConfiguracionAlgoritmo {
 public:
  /**
   * @brief Constructor por defecto.
   *
   * Inicializa el contenedor interno de configuraciones vacío.
   */
  ConfiguracionAlgoritmo();

  /**
   * @brief Añade una nueva configuración (clave, valor).
   * @param clave Identificador de la configuración.
   * @param valor Valor asociado a la clave.
   * @throws std::invalid_argument Si la clave ya existe en el contenedor.
   */
  void AñadirConfiguracion(const std::string& clave, const std::string& valor);

  /**
   * @brief Obtiene el valor asociado a una clave.
   * @param clave Identificador de la configuración a consultar.
   * @return Valor asociado a la clave.
   * @throws std::out_of_range Si la clave no existe en el contenedor.
   */
  std::string ObtenerConfiguracion(const std::string& clave) const;
  
 private:
  std::map<std::string, std::string> configuraciones_;
};

#endif