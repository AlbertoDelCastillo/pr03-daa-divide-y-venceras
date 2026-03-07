#include <iostream>
#include "divideyvenceras.h"
#include "instancia-vector.h"

int main() {
  std::cout << "=== Práctica Divide y Venceras ===" << std::endl;
  std::cout << std::endl;

  // Crear instancias de prueba
  std::cout << "Instancia 1: Con tamaño especificado (20 elementos)" << std::endl;
  InstanciaVector instancia1(20);
  instancia1.Mostrar();
  
  std::cout << std::endl;
  std::cout << "Instancia 2: Constructor por defecto + GenerarAleatorio()" << std::endl;
  InstanciaVector instancia2;
  instancia2.GenerarAleatorio();
  instancia2.Mostrar();
  
  std::cout << std::endl;
  std::cout << "Tamaño de instancia1: " << instancia1.GetTamaño() << std::endl;
  std::cout << "Tamaño de instancia2: " << instancia2.GetTamaño() << std::endl;

  return 0;
}