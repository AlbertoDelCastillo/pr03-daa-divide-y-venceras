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
 * @brief Programa principal para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file main.cc
 * @brief Punto de entrada principal del programa. Permite seleccionar modo normal o debug.
 */

#include <iostream>
#include "utilidades.h"

/**
 * @brief Función principal del programa.
 * Muestra el menú de selección de modo, ejecuta el modo elegido y gestiona la interacción con el usuario.
 * - Modo Normal: ejecuta experimentación automática y muestra tabla comparativa.
 * - Modo Debug: permite probar los algoritmos con instancias personalizadas y ver resultados.
 * @return Código de salida del programa.
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