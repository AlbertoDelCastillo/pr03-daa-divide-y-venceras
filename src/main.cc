/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 4: Programación Dinámica - Patrón Factory
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @file main.cc
 * @brief Punto de entrada del programa. Parsea los argumentos de línea
 *        de comandos y delega la ejecución en las funciones de utilidades.
 * @date Mar 15 2026
 * @version 2.0
 */
 
#include <iostream>
#include <string>
#include <unistd.h>
#include "utilidades.h"
 
int main(int argc, char* argv[]) {
  Argumentos args = ParsearArgumentos(argc, argv);
  if (args.error) {
    std::cerr << "Error: " << args.mensaje_error << "\nUse -h para ver la ayuda.\n";
    return 1;
  }
  if (args.mostrar_ayuda) {
    MostrarAyuda(argv[0]);
    return 0;
  }
  if (args.modo_experimentacion) {
    ModoExperimentacion();
    return 0;
  }
  if (args.ruta_instancia.empty() || args.ruta_algoritmo.empty()) {
    std::cerr << "Error: se requieren -i y -a. Use -h para ver la ayuda.\n";
    return 1;
  }
  ModoEmpleados(args.ruta_instancia, args.ruta_algoritmo);
  return 0;
}