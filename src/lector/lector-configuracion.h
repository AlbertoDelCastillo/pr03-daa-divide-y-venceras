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
 * @file lector-configuracion.h
 * @brief Declaración de la interfaz LectorConfiguracion para cargar
 *        parámetros de configuración del algoritmo desde fichero.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef LECTOR_CONFIGURACION_H
#define LECTOR_CONFIGURACION_H

#include <string>
#include "configuracion-algoritmo.h"

/**
 * @class LectorConfiguracion
 * @brief Interfaz abstracta para lectores de configuración.
 *
 * Define el contrato común para cargar una ConfiguracionAlgoritmo desde
 * distintos formatos de fichero (por ejemplo, JSON).
 */
class LectorConfiguracion {
 public:
    virtual ~LectorConfiguracion() = default;
    virtual ConfiguracionAlgoritmo LeerFichero(const std::string& ruta) = 0;
};

#endif