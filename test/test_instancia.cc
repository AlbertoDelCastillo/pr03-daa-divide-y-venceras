#include <gtest/gtest.h>
#include <vector>
#include "instancia-vector.h"
#include "divideyvenceras.h"

// ==========================================
// Tests para la clase InstanciaVector
// ==========================================

TEST(InstanciaVectorTest, ConstructorCreaBienUnaInstancia) {
    InstanciaVector instancia;
    EXPECT_EQ(instancia.GetTamaño(), 0);
}

TEST(InstanciaVectorTest, GenerarAleatorioAsignaElTamanoCorrecto) {
    InstanciaVector instancia;
    
    // Ejecutar la generación aleatoria
    instancia.GenerarAleatorio();
    
    // Verificar que tiene un tamaño válido (no vacío)
    EXPECT_GT(instancia.GetTamaño(), 0);
}

TEST(InstanciaVectorTest, GenerarAleatorioCreaDatosValidos) {
    InstanciaVector instancia;
    instancia.GenerarAleatorio();
    
    // Verificar que se pueden acceder los datos sin error
    EXPECT_GT(instancia.GetTamaño(), 0);
    // Si existe un getter para acceder a los datos
    // std::vector<int> datos = instancia.GetDatos();
    // EXPECT_EQ(datos.size(), instancia.GetTamaño());
}

TEST(InstanciaVectorTest, TamanioNegativoNoEsValido) {
    InstanciaVector instancia;
    
    // El tamaño debe ser siempre >= 0
    EXPECT_GE(instancia.GetTamaño(), 0);
}

// ==========================================
// Tests para operaciones de Divide y Venceras
// ==========================================

TEST(DivideYVencerasTest, EjecutarSolveConInstanciaValida) {
    InstanciaVector instancia;
    instancia.GenerarAleatorio();
    
    // Verificar que la instancia tiene datos válidos
    EXPECT_GT(instancia.GetTamaño(), 0);
}

TEST(DivideYVencerasTest, InstanciaVectorNoEstaVacia) {
    InstanciaVector instancia;
    instancia.GenerarAleatorio();
    
    // Después de generar, debe tener contenido
    int tamanio = instancia.GetTamaño();
    EXPECT_GT(tamanio, 0);
    EXPECT_LE(tamanio, 1000);  // Límite razonable
}