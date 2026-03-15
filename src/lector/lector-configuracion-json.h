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
 * @file lector-configuracion-json.h
 * @brief Declaración de la clase LectorConfiguracionJSON para cargar
 *        la configuración del algoritmo desde ficheros JSON.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef LECTOR_CONFIGURACION_JSON_H
#define LECTOR_CONFIGURACION_JSON_H

#include "lector-configuracion.h"

/**
 * @class LectorConfiguracionJSON
 * @brief Lector concreto de configuración en formato JSON.
 *
 * Implementa la interfaz LectorConfiguracion extrayendo del fichero JSON
 * los parámetros necesarios para construir el algoritmo y su small solver.
 */
class LectorConfiguracionJSON : public LectorConfiguracion {
 public:
    ConfiguracionAlgoritmo LeerFichero(const std::string& ruta) override;
};

#endif