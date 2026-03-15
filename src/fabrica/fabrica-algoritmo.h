/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Diseño y Análisis de Algoritmos 2025-2026
 * 3º Año de Carrera
 * Práctica 3: Divide y Vencerás - Planificación de Empleados
 *
 * @author Alberto Del Castillo Díaz alu0101627137@ull.edu.es
 * @author Bruno Morales Hernandez alu0101664309@ull.edu.es
 * @file fabrica-algoritmo.h
 * @brief Declaración de la clase FabricaAlgoritmos para crear instancias
 *        del algoritmo principal y su resolvedor de casos pequeños.
 * @date Mar 15 2026
 * @version 1.0
 */

#ifndef FABRICA_ALGORITMO_H
#define FABRICA_ALGORITMO_H

#include <iostream>

#include "algoritmo.h"
#include "planificacion-empleados.h"
#include "configuracion-algoritmo.h"
#include "small-solver.h"
#include "solver-gready.h"
#include "solver-pd.h"
#include "solver-greedy-mejorado.h"

/**
 * @class FabricaAlgoritmos
 * @brief Fábrica responsable de construir el algoritmo configurado.
 *
 * A partir de una ConfiguracionAlgoritmo, crea el resolvedor para instancias
 * pequeñas (SmallSolver) y el algoritmo principal de planificación de empleados.
 */
class FabricaAlgoritmos {
 public:
  Algoritmo* CrearAlgoritmo(ConfiguracionAlgoritmo& config, Instancia* datos);
};

#endif 