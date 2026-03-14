#ifndef SOLVER_GREADY_H
#define SOLVER_GREADY_H

#include "small-solver.h"

class SolverGready : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* isnt) override;
};

#endif