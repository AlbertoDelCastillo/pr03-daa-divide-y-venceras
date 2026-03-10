#include <iostream>
#include <string>
#include "utilidades.h"
#include "lector-json.h"
#include "instancia-empleados.h"
#include "planificacion-empleados.h"

int main() {
  std::cout << "1. Ordenacion\n2. Planificacion de Empleados\nOpcion: ";
  int modo;
  std::cin >> modo;
  if (modo == 1) {
    std::cout << "1. Normal\n2. Debug\nOpcion: ";
    int submodo;
    std::cin >> submodo;
    if (submodo == 1) ModoNormal();
    else if (submodo == 2) ModoDebug();
    else std::cout << "Opcion no valida." << std::endl;
  } else if (modo == 2) {
    ModoEmpleados();
  } else {
    std::cout << "Opcion no valida." << std::endl;
  }
  return 0;
}