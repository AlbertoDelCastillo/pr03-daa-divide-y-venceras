#include <gtest/gtest.h>
#include "mergesort.h"
#include "instancia-vector.h"

// ==========================================
// Tests para la clase MergeSort
// ==========================================

TEST(MergeSortTest, ConstructorCreaMergeSortCorrectamente) {
  InstanciaVector instancia(5);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoCero) {
  InstanciaVector instancia(0);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoUno) {
  InstanciaVector instancia(1);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoGrande) {
  InstanciaVector instancia(100);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoPequeño) {
  InstanciaVector instancia(1);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoMayor) {
  InstanciaVector instancia(10);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}

TEST(MergeSortTest, SolveConTamañoImpar) {
  InstanciaVector instancia(7);
  MergeSort mergesort(&instancia);
  EXPECT_NO_THROW(mergesort.Ejecutar());
}
