/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 3: Divide y Vencerás - Ordenación
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @brief Clase abstracta base para la creación de algoritmos.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file algoritmo.h
 * @brief Declaración de la clase abstracta Algoritmo para la ejecución de algoritmos.
 */

#ifndef ALGORITMO_H
#define ALGORITMO_H

/**
 * @class Algoritmo
 * @brief Clase abstracta desde la que se crearán todos los algoritmos.
 * Define la interfaz común para ejecutar cualquier algoritmo.
 */
class Algoritmo {
 public:
  /**
   * @brief Método virtual puro para ejecutar el algoritmo.
   * Debe ser implementado por las clases derivadas.
   */
  virtual void Ejecutar() = 0;
};

#endif