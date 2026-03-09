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
 * @brief Clase abstracta para algoritmos con metodología Divide y Vencerás.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file divideyvenceras.h
 * @brief Declaración de la clase abstracta DivideYVenceras para algoritmos de tipo divide y vencerás.
 */

#ifndef DIVIDEYVENCERAS_H
#define DIVIDEYVENCERAS_H

#include <vector>
#include "algoritmo.h"
#include "instancia.h"
#include "solucion.h"

/**
 * @class DivideYVenceras
 * @brief Clase abstracta que representa algoritmos con metodología divide y vencerás.
 * Define un método Solve() común para todas las clases hijas, y cuatro métodos virtuales
 * que deben ser implementados por las clases derivadas: Small, SolveSmall, Divide y Combine.
 */
class DivideYVenceras : public Algoritmo {
 public:
  /**
   * @brief Constructor inicial.
   * Inicializa el algoritmo con la instancia del problema.
   * @param inst Valor inicial de la instancia.
   */
  DivideYVenceras(Instancia* inst);

  /**
   * @brief Override del método ejecutar para indicar a Algoritmo cómo resolver la ejecución.
   */
  void Ejecutar() override;

  /**
   * @brief Método Solve encargado de resolver el problema usando la lógica de divide y vencerás.
   * Aplica recursivamente la metodología, utilizando los métodos Small, SolveSmall, Divide y Combine.
   * @param inst Instancia a resolver.
   * @param tamaño Tamaño de la instancia.
   * @return Solución al problema.
   */
  Solucion* Solve(Instancia* inst, int tamaño);

  /**
   * @brief Método virtual Small para comprobar la condición de caso base.
   * Indica si el tamaño de una instancia es lo suficientemente pequeño para resolverlo directamente.
   * @param inst Instancia a evaluar.
   * @return true si es caso base, false en caso contrario.
   */
  virtual bool Small(Instancia* inst) = 0;
  
  /**
   * @brief Método virtual SolveSmall para resolver el caso base.
   * Ejecuta el algoritmo en el caso pequeño.
   * @param inst Instancia pequeña a resolver.
   * @return Solución parcial al problema.
   */
  virtual Solucion* SolveSmall(Instancia* inst) = 0;
  
  /**
   * @brief Método virtual Divide para partir una instancia en subinstancias más pequeñas.
   * @param inst Instancia a dividir.
   * @param tamaño Tamaño de la instancia.
   * @return Vector de subinstancias derivadas de la inicial.
   */
  virtual std::vector<Instancia*> Divide(Instancia* inst, int tamaño) = 0;
  
  /**
   * @brief Método virtual Combine para unir soluciones parciales.
   * Ejecuta el algoritmo para combinar dos soluciones parciales en una solución global.
   * @param sol_parcial_1 Primera solución parcial a unir.
   * @param sol_parcial_2 Segunda solución parcial a unir.
   * @return Solución al problema resultado de unir dos soluciones parciales.
   */
  virtual Solucion* Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) = 0;

 protected:
  Instancia* problema_inicial_;
  Solucion* solucion_problema_;
};

#endif