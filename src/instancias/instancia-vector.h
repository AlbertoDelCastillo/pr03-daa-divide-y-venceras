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
 * @file instancia-vector.h
 * @brief Declaración de la clase InstanciaVector para representar instancias de tipo vector de enteros.
 * @date Mar 8 2026
 * @version 1.0
 */

#ifndef INSTANCIA_VECTOR_H
#define INSTANCIA_VECTOR_H

#include <vector>
#include "instancia.h"

/**
 * @class InstanciaVector
 * @brief Representa una instancia de tipo vector de enteros para algoritmos de ordenación.
 * Hereda de Instancia y permite almacenar, modificar y visualizar un vector de datos.
 */
class InstanciaVector : public Instancia {
 public:
  InstanciaVector();
  InstanciaVector(int);
  void GenerarAleatorio();
  void Mostrar() override;
  int GetTamaño();
  int GetDato(int) const;
  void AgregarDato(int);
  ~InstanciaVector() = default;
  void SetDato(int, int);

 private:
  std::vector<int> datos_;
};

#endif