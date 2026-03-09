cmake_minimum_required(VERSION 3.14)
project(PracticaDivideYVenceras)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Añadir subdirectorios al include path
include_directories(
    src/algoritmo
    src/isntancias
    src/solucion
    src
)

# Crear la librería con el código fuente (excepto main.cc)
add_library(MiCodigo 
    src/algoritmo/divideyvenceras.cc
    src/algoritmo/mergesort.cc
    src/algoritmo/quicksort.cc
    src/isntancias/instancia-vector.cc
    src/solucion/solucion-vector.cc
    src/utilidades.cc
)

# Ejecutable principal
add_executable(programa_principal src/main.cc)
target_link_libraries(programa_principal MiCodigo)
