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
 * @brief Clase abstracta para representar la solución al problema de ordenación.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file solucion.h
 * @brief Declaración de la clase abstracta Solucion para representar la solución de un algoritmo.
 */

#ifndef SOLUCION_H
#define SOLUCION_H

/**
 * @class Solucion
 * @brief Clase abstracta para representar la solución al problema.
 * Incluye métodos para mostrar los valores y copiar los datos de otra solución.
 */
class Solucion {
 public:
  /**
   * @brief Método virtual para mostrar los valores de la solución.
   */
  virtual void Mostrar() = 0;

  // /**
  //  * @brief Método virtual para copiar los valores de otra solución.
  //  * @param otra Otra solución de la cual se van a copiar los datos.
  //  */
  // virtual void CopiarValores(Solucion* otra) = 0;

  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~Solucion() = default;
};

#endif