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
 * @file lector-instancia.h
 * @brief Declaración de la interfaz abstracta LectorInstancia para la lectura
 *        de instancias del problema desde ficheros externos.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef LECTOR_INSTANCIA_H
#define LECTOR_INSTANCIA_H

#include <string>
#include "instancia.h"

/**
 * @class LectorInstancia
 * @brief Interfaz abstracta para la lectura de datos del problema.
 */
class LectorInstancia {
 public:
  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~LectorInstancia() = default;

  /**
   * @brief Lee un fichero y construye una instancia del problema.
   * @param ruta_fichero Ruta al archivo que contiene los datos.
   * @return Puntero a la Instancia generada dinámicamente.
   */
  virtual Instancia* LeerDesdeFichero(const std::string& ruta_fichero) = 0;
};

#endif