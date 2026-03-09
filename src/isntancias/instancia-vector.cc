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

#include "instancia-vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * @brief Constructor por defecto de la clase InstanciaVector.
 * Inicializa el vector vacío.
 */
InstanciaVector::InstanciaVector() : datos_() {}

/**
 * @brief Constructor que especifica el tamaño del vector.
 * Si el tamaño es mayor que cero, inicializa el vector y genera valores aleatorios.
 * @param tamaño Tamaño inicial del vector.
 */
InstanciaVector::InstanciaVector(int tamaño) {
  if (tamaño > 0) {
    datos_.resize(tamaño);
    GenerarAleatorio();
  }
}

/**
 * @brief Genera valores aleatorios para el vector.
 * Si el vector está vacío, lo inicializa con tamaño aleatorio entre 10 y 100.
 * Asigna valores aleatorios entre 0 y 99 a cada posición.
 */
void InstanciaVector::GenerarAleatorio() {
  if (datos_.empty()) {
    srand(time(nullptr));
    int tamanio = 10 + (rand() % 91);
    datos_.resize(tamanio);
  }
  for (int i = 0; i < datos_.size(); i++) {
    datos_[i] = rand() % 100;
  }
}

/**
 * @brief Muestra los valores del vector por pantalla.
 * Imprime el tamaño y los elementos del vector.
 */
void InstanciaVector::Mostrar() {
  std::cout << "Vector de tamaño " << datos_.size() << ": [";
  for (int i = 0; i < datos_.size(); i++) {
    std::cout << datos_[i];
    if (i < datos_.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

/**
 * @brief Obtiene el tamaño del vector.
 * @return Tamaño del vector.
 */
int InstanciaVector::GetTamaño() {
  return datos_.size();
}

/**
 * @brief Obtiene el dato en la posición indicada.
 * @param indice Posición del dato.
 * @return Valor del dato en esa posición, o -1 si el índice es inválido.
 */
int InstanciaVector::GetDato(int indice) const {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    return datos_[indice];
  }
  return -1;
}

/**
 * @brief Agrega un dato al final del vector.
 * @param valor Valor a agregar.
 */
void InstanciaVector::AgregarDato(int valor) {
  datos_.push_back(valor);
}

/**
 * @brief Establece el dato en la posición indicada.
 * @param indice Posición del dato.
 * @param valor Valor a establecer.
 */
void InstanciaVector::SetDato(int indice, int valor) {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    datos_[indice] = valor;
  }
}