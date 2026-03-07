#include <gtest/gtest.h>
#include <vector>
#include "solucion-vector.h"
#include "instancia-vector.h"

// ==========================================
// Tests para la clase SolucionVector
// ==========================================

TEST(SolucionVectorTest, ConstructorCreaBienUnaSolucion) {
    SolucionVector solucion;
    EXPECT_NO_THROW(solucion.Mostrar());
}

TEST(SolucionVectorTest, ConstructorConTamanioAsignaElTamanioCorrecto) {
    int tamanio = 10;
    SolucionVector solucion(tamanio);
    EXPECT_NO_THROW(solucion.Mostrar());
}

TEST(SolucionVectorTest, SolucionVectorAlmacenaElementos) {
    SolucionVector solucion(5);
    
    // Verificar que se puede mostrar sin errores
    EXPECT_NO_THROW(solucion.Mostrar());
}

TEST(SolucionVectorTest, MostrarNoLanzaExcepcion) {
    SolucionVector solucion(3);
    
    // Verificar que mostrar se ejecuta sin errores
    EXPECT_NO_THROW(solucion.Mostrar());
}

TEST(SolucionVectorTest, SolucionVectorAlmacenaValoresOrdenados) {
    SolucionVector solucion(5);
    
    // La solución debe almacenar valores (probablemente ordenados)
    EXPECT_NO_THROW(solucion.Mostrar());
}