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
 * @file main.cc
 * @brief Programa principal para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
 */

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