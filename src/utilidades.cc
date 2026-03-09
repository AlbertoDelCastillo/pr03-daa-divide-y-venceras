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
 * @brief Funciones auxiliares para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file utilidades.cc
 * @brief Implementación de funciones auxiliares para modos de ejecución y visualización de resultados.
 */

#include "utilidades.h"

/**
 * @brief Muestra una tabla comparativa de tiempos de ejecución.
 * Imprime por pantalla los tamaños de las instancias y los tiempos de ejecución de MergeSort y QuickSort.
 * @param tamaños Vector de tamaños de instancias.
 * @param tiempos_merge Vector de tiempos de MergeSort.
 * @param tiempos_quick Vector de tiempos de QuickSort.
 */
void MostrarTablaTiempos(const std::vector<int>& tamaños,
                         const std::vector<double>& tiempos_merge,
                         const std::vector<double>& tiempos_quick) {
  std::cout << std::setw(10) << "Tamaño"
            << std::setw(15) << "MergeSort (ms)"
            << std::setw(15) << "QuickSort (ms)" << std::endl;
  std::cout << "---------------------------------------------" << std::endl;
  for (size_t i = 0; i < tamaños.size(); ++i) {
    std::cout << std::setw(10) << tamaños[i]
              << std::setw(15) << tiempos_merge[i]
              << std::setw(15) << tiempos_quick[i] << std::endl;
  }
}

/**
 * @brief Ejecuta el modo normal: genera instancias aleatorias, ejecuta ambos algoritmos y mide tiempos.
 * Recorre varios tamaños de instancia, ejecuta MergeSort y QuickSort, mide el tiempo de cada uno
 * y muestra una tabla comparativa por pantalla.
 */
void ModoNormal() {
  std::vector<int> tamaños = {10, 100, 500, 1000, 5000, 10000};
  std::vector<double> tiempos_merge;
  std::vector<double> tiempos_quick;
  for (int tamaño : tamaños) {
    InstanciaVector instancia(tamaño);
    MergeSort mergesort(&instancia);
    auto inicio_merge = std::chrono::high_resolution_clock::now();
    mergesort.Solve(&instancia);
    auto fin_merge = std::chrono::high_resolution_clock::now();
    double tiempo_merge = std::chrono::duration<double, std::milli>(fin_merge - inicio_merge).count();
    tiempos_merge.push_back(tiempo_merge);
    QuickSort quicksort(&instancia);
    auto inicio_quick = std::chrono::high_resolution_clock::now();
    quicksort.Solve(&instancia);
    auto fin_quick = std::chrono::high_resolution_clock::now();
    double tiempo_quick = std::chrono::duration<double, std::milli>(fin_quick - inicio_quick).count();
    tiempos_quick.push_back(tiempo_quick);
  }
  MostrarTablaTiempos(tamaños, tiempos_merge, tiempos_quick);
}

/**
 * @brief Ejecuta el modo debug: solicita algoritmo y tamaño, muestra instancia y solución.
 * Permite al usuario seleccionar el algoritmo y el tamaño de la instancia, muestra la instancia generada
 * y la solución final ordenada por pantalla.
 */
void ModoDebug() {
  int tamaño;
  int opcion;
  std::cout << "Seleccione algoritmo:\n";
  std::cout << "1. MergeSort\n";
  std::cout << "2. QuickSort\n";
  std::cout << "Opción: ";
  std::cin >> opcion;
  std::cout << "Introduzca el tamaño de la instancia: ";
  std::cin >> tamaño;
  InstanciaVector instancia(tamaño);
  std::cout << "Instancia generada:\n";
  instancia.Mostrar();
  if (opcion == 1) {
    MergeSort mergesort(&instancia);
    Solucion* solucion = mergesort.Solve(&instancia);
    std::cout << "Solución final (MergeSort):\n";
    solucion->Mostrar();
    delete solucion;
  } else if (opcion == 2) {
    QuickSort quicksort(&instancia);
    Solucion* solucion = quicksort.Solve(&instancia);
    std::cout << "Solución final (QuickSort):\n";
    solucion->Mostrar();
    delete solucion;
  } else {
    std::cout << "Opción no válida.\n";
  }
}