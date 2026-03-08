#include <gtest/gtest.h>
#include "quicksort.h"
#include "instancia-vector.h"

// ==========================================
// Tests para la clase QuickSort
// ==========================================

TEST(QuickSortTest, ConstructorCreaQuickSortCorrectamente) {
  InstanciaVector instancia(5);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoCero) {
  InstanciaVector instancia(0);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoUno) {
  InstanciaVector instancia(1);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoGrande) {
  InstanciaVector instancia(100);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoPequeño) {
  InstanciaVector instancia(1);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoMayor) {
  InstanciaVector instancia(10);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}

TEST(QuickSortTest, SolveConTamañoImpar) {
  InstanciaVector instancia(7);
  QuickSort quicksort(&instancia);
  EXPECT_NO_THROW(quicksort.Ejecutar());
}