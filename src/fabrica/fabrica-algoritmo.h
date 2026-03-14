#ifndef FABRICA_ALGORITMO_H
#define FABRICA_ALGORITMO_H

#include <iostream>

#include "algoritmo.h"
#include "planificacion-empleados.h"
#include "configuracion-algoritmo.h"
#include "small-solver.h"
#include "solver-gready.h"
#include "solver-pd.h"

/**
 * Clase encargada de construir el algoritmo de ordenacaion de emplados.
 * A partir de una una configuracion de algoritmo, crea una instacia de algoritmo
 * con dichas configuraciones.
 */
class FabricaAlgoritmos {
 public:
  Algoritmo* CrearAlgoritmo(ConfiguracionAlgoritmo& config, Instancia* datos);
};

#endif 