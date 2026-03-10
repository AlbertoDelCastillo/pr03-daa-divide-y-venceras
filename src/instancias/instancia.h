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
 * @brief Clase abstracta para representar instancias de datos de entrada de algoritmos.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file instancia.h
 * @brief Declaración de la clase abstracta Instancia para representar datos de entrada.
 */

#ifndef INSTANCIA_H
#define INSTANCIA_H

/**
 * @class Instancia
 * @brief Clase abstracta que almacena los datos de entrada del algoritmo.
 * Sus subclases se encargan de definir los métodos para instanciar y mostrar los datos.
 */
class Instancia {
 public:
  /**
   * @brief Método virtual para mostrar los valores de la instancia.
   */
  virtual void Mostrar() = 0;

  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~Instancia() = default;
};

#endif