cmake_minimum_required(VERSION 3.14)
project(PracticaDivideYVenceras)

# Configurar el estandar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 2. Crear una libreria con tu codigo fuente (EXCEPTO el main.cpp)
add_library(MiCodigo 
    src/divideyvenceras.cc
    src/instancia-vector.cc
    src/solucion-vector.cc
    src/mergesort.cc
    src/quicksort.cc
    src/main.cc
    src/utilidades.cc
)
target_include_directories(MiCodigo PUBLIC src)

# ---------------------------------------------------
# 3. EJECUTABLE PRINCIPAL (El programa de tu practica)
# ---------------------------------------------------
add_executable(programa_principal src/main.cc)
target_link_libraries(programa_principal MiCodigo)
