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
 * @file lector-json.h
 * @brief Declaración de la clase LectorJSON para la lectura de instancias
 *        del problema de planificación desde ficheros en formato JSON.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef LECTOR_JSON_
#define LECTOR_JSON_H

#include <string>
#include "lector-instancia.h"
#include "instancia-empleados.h"

/**
 * @class LectorJSON
 * @brief Clase concreta que implementa la lectura de instancias desde archivos JSON.
 */
class LectorJSON : public LectorInstancia {
 public:
  LectorJSON() = default;
  ~LectorJSON() = default;
  Instancia* LeerDesdeFichero(const std::string&) override;
};

#endif