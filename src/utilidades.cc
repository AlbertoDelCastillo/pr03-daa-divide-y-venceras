#include "utilidades.h"


/**
 * Muestra una tabla comparativa de tiempos de ejecución.
 * @param tamaños Vector de tamaños de instancias
 * @param tiempos_merge Vector de tiempos de MergeSort
 * @param tiempos_quick Vector de tiempos de QuickSort
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
 * Ejecuta el modo normal: genera instancias aleatorias, ejecuta ambos algoritmos y mide tiempos.
 */
void ModoNormal() {
  std::vector<int> tamaños = {10, 100, 500, 1000, 5000, 10000};
  std::vector<double> tiempos_merge;
  std::vector<double> tiempos_quick;

  for (int tamaño : tamaños) {
    InstanciaVector instancia(tamaño);

    // MergeSort
    MergeSort mergesort(&instancia);
    auto inicio_merge = std::chrono::high_resolution_clock::now();
    mergesort.Solve(&instancia, tamaño);
    auto fin_merge = std::chrono::high_resolution_clock::now();
    double tiempo_merge = std::chrono::duration<double, std::milli>(fin_merge - inicio_merge).count();
    tiempos_merge.push_back(tiempo_merge);

    // QuickSort
    QuickSort quicksort(&instancia);
    auto inicio_quick = std::chrono::high_resolution_clock::now();
    quicksort.Solve(&instancia, tamaño);
    auto fin_quick = std::chrono::high_resolution_clock::now();
    double tiempo_quick = std::chrono::duration<double, std::milli>(fin_quick - inicio_quick).count();
    tiempos_quick.push_back(tiempo_quick);
  }

  MostrarTablaTiempos(tamaños, tiempos_merge, tiempos_quick);
}

/**
 * Ejecuta el modo debug: solicita algoritmo y tamaño, muestra instancia y solución.
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
    Solucion* solucion = mergesort.Solve(&instancia, tamaño);
    std::cout << "Solución final (MergeSort):\n";
    solucion->Mostrar();
    delete solucion;
  } else if (opcion == 2) {
    QuickSort quicksort(&instancia);
    Solucion* solucion = quicksort.Solve(&instancia, tamaño);
    std::cout << "Solución final (QuickSort):\n";
    solucion->Mostrar();
    delete solucion;
  } else {
    std::cout << "Opción no válida.\n";
  }
}