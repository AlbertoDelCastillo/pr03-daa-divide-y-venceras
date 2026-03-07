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