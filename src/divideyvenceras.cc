#include "divideyvenceras.h"

/**
 * Defincion del constructor de la clase
 */
DivideYVenceras::DivideYVenceras(Instancia* inst) : problema_inicial_{inst} {}

/**
 * Definicion del metodo ejecutar.
 * Llama al metodo solve con el valor del atributo instancia ademas de
 * darle valor al atributo solucion
 */
void DivideYVenceras::Ejecutar() {
  Instancia* inst = this->problema_inicial_;
  int tamaño = inst->GetTamaño();
  this->solucion_problema_->CopiarValores(this->Solve(inst, tamaño));
}

/**
 * Definicion de metodo Solve con la logica de Divide y Venceras
 */
Solucion* DivideYVenceras::Solve(Instancia* inst, int tamaño) {
  if (Small(inst)) {
    return SolveSmall(inst);
  } 
  else {
    std::vector<Instancia*> m = Divide(inst, tamaño); 
    Solucion* s1 = Solve(m[0], tamaño / 2);
    Solucion* s2 = Solve(m[1], tamaño / 2);
    Solucion* S = Combine(s1, s2);
    delete m[0];
    delete m[1];
    return S; 
  }
}