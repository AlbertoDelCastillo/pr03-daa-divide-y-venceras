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
 * @file utilidades.h
 * @brief Declaración de funciones auxiliares para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
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

void MostrarTablaTiempos(const std::vector<int>&, const std::vector<double>&, const std::vector<double>&);
void ModoNormal();
void ModoDebug();
void ModoEmpleados();

#endif