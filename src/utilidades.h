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
#include "lector-json.h"
#include "instancia-empleados.h"
#include "planificacion-empleados.h"
#include "fabrica/fabrica-algoritmo.h"
#include "lector/lector-configuracion-json.h"

/**
 * @struct ResultadoExperimento
 * @brief Almacena los resultados de ejecutar un algoritmo sobre una instancia.
 */
struct ResultadoExperimento {
  int empleados;
  int dias;
  int turnos;
  int valor;
  double tiempo_ms;
};

/**
 * @struct Argumentos
 * @brief Almacena los argumentos parseados de la línea de comandos.
 */
struct Argumentos {
  std::string ruta_instancia;
  std::string ruta_algoritmo;
  bool modo_experimentacion = false;
  bool mostrar_ayuda        = false;
  bool error                = false;
  std::string mensaje_error;
};

Argumentos ParsearArgumentos(int, char**);
void MostrarAyuda(const std::string&);
void MostrarTablaComparativa(const std::vector<ResultadoExperimento>&, const std::vector<ResultadoExperimento>&);
void ModoExperimentacion();
void ModoEmpleados(const std::string&, const std::string&);

#endif