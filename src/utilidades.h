#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>

#include "instancia-vector.h"
#include "mergesort.h"
#include "quicksort.h"

/**
 * Muestra una tabla comparativa de tiempos de ejecución.
 * @param tamaños Vector de tamaños de instancias
 * @param tiempos_merge Vector de tiempos de MergeSort
 * @param tiempos_quick Vector de tiempos de QuickSort
 */
void MostrarTablaTiempos(const std::vector<int>& tamaños,
                         const std::vector<double>& tiempos_merge,
                         const std::vector<double>& tiempos_quick);

/**
 * Ejecuta el modo normal: genera instancias aleatorias, ejecuta ambos algoritmos y mide tiempos.
 */
void ModoNormal();

/**
 * Ejecuta el modo debug: solicita algoritmo y tamaño, muestra instancia y solución.
 */
void ModoDebug();

#endif