#include "instancia-vector.h"
#include <cstdlib>
#include <ctime>
#include <iostream>

/**
 * Constructor por defecto de la clase
 */
InstanciaVector::InstanciaVector() : datos_() {}

/**
 * Constructor que especifica el tamaño del vector
 */
InstanciaVector::InstanciaVector(int tamaño) {
  if (tamaño > 0) {
    datos_.resize(tamaño);
    GenerarAleatorio();
  }
}

/**
 * Definicion del metodo generar aleatorio
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
 * Metodo virtual para mostrar los valores de la instancia
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
 * Metodo para obtener el tamaño de la instancia
 * @return Tamaño de la instancia
 */
int InstanciaVector::GetTamaño() {
  return datos_.size();
}

/**
 * Obtiene el dato en la posición indicada
 * @param indice Posición del dato
 * @return Valor del dato en esa posición
 */
int InstanciaVector::GetDato(int indice) const {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    return datos_[indice];
  }
  return -1; // O lanzar excepción si prefieres
}

/**
 * Agrega un dato al final del vector
 * @param valor Valor a agregar
 */
void InstanciaVector::AgregarDato(int valor) {
  datos_.push_back(valor);
}

/**
 * Establece el dato en la posición indicada
 * @param indice Posición del dato
 * @param valor Valor a establecer
 */
void InstanciaVector::SetDato(int indice, int valor) {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    datos_[indice] = valor;
  }
}