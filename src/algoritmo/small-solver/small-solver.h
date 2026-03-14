#ifndef SMALL_SOLVER_H
#define SMALL_SOLVER_H

#include "solucion.h"
#include "instancia.h"

class SmallSolver {
 public:
  virtual Solucion* ResolverDiaPequeño(Instancia* isnt) = 0;
};

#endif