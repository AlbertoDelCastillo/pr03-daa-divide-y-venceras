#include "solucion-vector.h"

/**
 * Constructor de la clase
 */
SolucionVector::SolucionVector(int tamaño) {
  datos_.resize(tamaño);
}

/**
 * Metodo virtual para mostrar los valores de la solucion
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
 * Metodo virtual para copiar el valor de de una solucion
 * @param otro Otra solucion la cual se va a copiar los datos
 */
void SolucionVector::CopiarValores(Solucion* otra) {
  SolucionVector* otraVector = dynamic_cast<SolucionVector*>(otra);
  if (otraVector != nullptr) {
    datos_ = otraVector->datos_;
  }
}


/**
 * Getter para obtener el tamaño
 * @return tamaño de los datos
 */
int SolucionVector::GetTamaño() {
  return static_cast<int>(datos_.size());
}

/**
 * Obtiene el dato en la posición indicada
 */
int SolucionVector::GetDato(int indice) const {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    return datos_[indice];
  }
  return -1;  // O lanzar excepción
}

/**
 * Establece el dato en la posición indicada
 */
void SolucionVector::SetDato(int indice, int valor) {
  if (indice >= 0 && indice < static_cast<int>(datos_.size())) {
    datos_[indice] = valor;
  }
}