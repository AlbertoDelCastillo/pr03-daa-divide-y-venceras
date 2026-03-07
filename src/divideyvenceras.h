#ifndef DIVIDEYVENCERAS_H
#define DIVIDEYVENCERAS_H

#include<vector>

#include "algoritmo.h"
#include "instancia.h"
#include "solucion.h"

/**
 * Clase abstracata que representa algoritmos con metodologia divide y venceras
 * Define un metodo solve() que es igual para todas las clases hijas, y 4 
 * metodos que deben de definir las clases hijas: Small, SolveSmall, Divide
 * y Combine.
 */
class DivideYVenceras : public Algoritmo {
 public:
  /**
   * Constructor incial
   * @param inst Valor incial de la instancia
   */
  DivideYVenceras(Instancia* inst);

  /**
   * Override de metodo ejecutar para indicar a algoritmo como resolver la 
   * ejecucion
   */
  void Ejecutar() override;

  /**
   * Metodo solve encargado de resolver el problema usando la logica de divide
   * y venceras
   */
  Solucion* Solve(Instancia* inst, int tamaño);

  /**
   * Metodo virtual Small para comprobar la condicion de que sea pequeño
   * @param inst Indica si el tamaño de una isntancia es lo sufuciientemente 
   *  pequeño para poder resolverlo directamente.´
   * @return true si es lo suficientemente pequeño, false en caso contrario
   */
  virtual bool Small(Instancia* inst) = 0;
  
  /**
   * Metodo virtual SolveSmall para ejecutar el algoritmo en el caso pequeño
   * @param inst Valor de la instancia la cual se va a resolver
   * @return Solucion parcial al problema
   */
  virtual Solucion* SolveSmall(Instancia* inst) = 0;
  
  /**
   * Metodo virtual Divide para partir una instancia en subinstancias mas
   * pequeñas
   * @param inst Valor de la instancia a dividir
   * @return Subintancia de la incial
   */
  virtual std::vector<Instancia*> Divide(Instancia* inst, int tamaño) = 0;
  
  /**
   * Metodo virtual Combine para ejecutar el algoritmo en el caso pequeño
   * @param sol_parcial_1 Primera solucion parcial a unir
   * @param sol_parcial_2 Segunda solucion parcial a unir
   * @return Solcion al problema resultado de unir 2 soluciones parciales
   */
  virtual Solucion* Combine(Solucion* sol_parcial_1, Solucion* sol_parcial_2) = 0;

 protected:
  Instancia* problema_inicial_;
  Solucion* solucion_problema_;
};

#endif