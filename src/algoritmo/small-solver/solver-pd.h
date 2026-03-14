#ifndef SOLVER_PD_H
#define SOLVER_PD_H

#include <stdexcept>
#include <vector>

#include "instancia-empleados.h"
#include "small-solver.h"
#include "solucion-empleados.h"


class SolverPD : public SmallSolver {
 public:
  Solucion* ResolverDiaPequeño(Instancia* isnt) override;
};

#endif