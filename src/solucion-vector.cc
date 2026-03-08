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
 * @brief Implementación de la clase SolucionVector para representar soluciones de ordenación.
 * @date Mar 8 2026
 * @version 1.0
 */

#include "solucion-vector.h"

/**
 * @brief Constructor de la clase SolucionVector.
 * Inicializa el vector de solución con el tamaño especificado.
 * @param tamaño Tamaño inicial del vector de solución.
 */
SolucionVector::SolucionVector(int tamaño) {
  datos_.resize(tamaño);
}

/**
 * @brief Muestra los valores de la solución por pantalla.
 * Imprime los elementos del vector en formato de lista.
 */
void SolucionVector::Mostrar() {
  std::cout << "[";
  for (size_t i = 0; i < datos_.size(); ++i) {
    std::cout << datos_[i];
    if (i < datos_.size() - 1) {
      std::cout << ", ";
    }
  }
  std::cout << "]" << std::endl;
}

/**
 * @brief Copia los valores de otra solución en esta.
 * @param otra Otra solución de la cual se van a copiar los datos.
 */
void SolucionVector::CopiarValores(Solucion* otra) {
  SolucionVector* otraVector = dynamic_cast<SolucionVector*>(otra);
  if (otraVector != nullptr) {
    datos_ = otraVector->datos_;
  }
}

/**
 * @brief Obtiene el tamaño del vector de solución.
 * @return Tamaño de los datos.
 */
int SolucionVector::GetTamaño() {
  return static_cast<int>(datos_.size());
}

/**
 * @brief Obtiene el dato en la posición indicada.
 * @param indice Posición del dato.
 * @return Valor del dato en esa posición, o -1 si el índice es inválido.
 */
int SolucionVector::GetDato(int indice) const {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    return datos_[indice];
  }
  return -1;
}

/**
 * @brief Establece el dato en la posición indicada.
 * @param indice Posición del dato.
 * @param valor Valor a establecer.
 */
void SolucionVector::SetDato(int indice, int valor) {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    datos_[indice] = valor;
  }
}