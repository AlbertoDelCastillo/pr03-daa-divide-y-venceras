#ifndef SOLVER_PD_H
#define SOLVER_PD_H

#include "small-solver.h"

class SolverPD : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* isnt) override;
};

#endif