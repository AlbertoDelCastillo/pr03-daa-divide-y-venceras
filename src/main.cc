#include <iostream>

#include "utilidades.h"

/**
 * Punto de entrada principal del programa.
 */
int main() {
  std::cout << "=== Práctica Divide y Venceras ===" << std::endl;
  std::cout << "Seleccione modo:\n";
  std::cout << "1. Normal\n";
  std::cout << "2. Debug\n";
  std::cout << "Opción: ";
  int modo;
  std::cin >> modo;
  if (modo == 1) {
    ModoNormal();
  } else if (modo == 2) {
    ModoDebug();
  } else {
    std::cout << "Opción no válida.\n";
  }
  return 0;
}