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
 * @brief Implementación de la clase InstanciaVector para almacenamiento y visualización de vectores.
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file instancia-vector.h
 * @brief Declaración de la clase InstanciaVector para representar instancias de tipo vector de enteros.
 */

#ifndef INSTANCIA_VECTOR_H
#define INSTANCIA_VECTOR_H

#include <vector>
#include "instancia.h"

/**
 * @class InstanciaVector
 * @brief Representa una instancia de tipo vector de enteros para algoritmos de ordenación.
 * Hereda de Instancia y permite almacenar, modificar y visualizar un vector de datos.
 */
class InstanciaVector : public Instancia {
 public:
  /**
   * @brief Constructor por defecto de la clase InstanciaVector.
   * Inicializa el vector vacío.
   */
  InstanciaVector();

  /**
   * @brief Constructor que especifica el tamaño del vector.
   * Si el tamaño es mayor que cero, inicializa el vector y genera valores aleatorios.
   * @param tamanio Tamaño inicial del vector de datos.
   */
  InstanciaVector(int tamanio);

  /**
   * @brief Override del método para generar valores aleatorios en el vector.
   */
  void GenerarAleatorio() override;

  /**
   * @brief Muestra los valores del vector por pantalla.
   */
  void Mostrar() override;

  /**
   * @brief Obtiene el tamaño de la instancia.
   * @return Tamaño del vector.
   */
  int GetTamaño() override;

  /**
   * @brief Obtiene el dato en la posición indicada.
   * @param indice Posición del dato.
   * @return Valor del dato en esa posición.
   */
  int GetDato(int indice) const;

  /**
   * @brief Agrega un dato al final del vector.
   * @param valor Valor a agregar.
   */
  void AgregarDato(int valor);

  /**
   * @brief Destructor por defecto.
   */
  ~InstanciaVector() = default;

  /**
   * @brief Establece el dato en la posición indicada.
   * @param indice Posición del dato.
   * @param valor Valor a establecer.
   */
  void SetDato(int indice, int valor);

 private:
  std::vector<int> datos_;
};

#endif