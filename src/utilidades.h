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
 * @brief Declaración de funciones auxiliares para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
 */

/**
 * @file utilidades.h
 * @brief Declaración de funciones auxiliares para modos de ejecución y visualización de resultados.
 */

#ifndef UTILIDADES_H
#define UTILIDADES_H

#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include "instancia-vector.h"
#include "mergesort.h"
#include "quicksort.h"
#include "lector-json.h"
#include "instancia-empleados.h"
#include "planificacion-empleados.h"

/**
 * @brief Muestra una tabla comparativa de tiempos de ejecución.
 * Imprime por pantalla los tamaños de las instancias y los tiempos de ejecución de MergeSort y QuickSort.
 * @param tamaños Vector de tamaños de instancias.
 * @param tiempos_merge Vector de tiempos de MergeSort.
 * @param tiempos_quick Vector de tiempos de QuickSort.
 */
void MostrarTablaTiempos(const std::vector<int>& tamaños,
                         const std::vector<double>& tiempos_merge,
                         const std::vector<double>& tiempos_quick);

/**
 * @brief Ejecuta el modo normal: genera instancias aleatorias, ejecuta ambos algoritmos y mide tiempos.
 * Recorre varios tamaños de instancia, ejecuta MergeSort y QuickSort, mide el tiempo de cada uno
 * y muestra una tabla comparativa por pantalla.
 */
void ModoNormal();

/**
 * @brief Ejecuta el modo debug: solicita algoritmo y tamaño, muestra instancia y solución.
 * Permite al usuario seleccionar el algoritmo y el tamaño de la instancia, muestra la instancia generada
 * y la solución final ordenada por pantalla.
 */
void ModoDebug();

void ModoEmpleados();


#endif