cmake_minimum_required(VERSION 3.14)
project(PracticaDivideYVenceras)

# Configurar el estandar de C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Descargar Google Test automaticamente de internet
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# 2. Crear una libreria con tu codigo fuente (EXCEPTO el main.cpp)
add_library(MiCodigo 
    src/divideyvenceras.cc
    src/instancia-vector.cc
    src/solucion-vector.cc
)
target_include_directories(MiCodigo PUBLIC src)

# ---------------------------------------------------
# 3. EJECUTABLE PRINCIPAL (El programa de tu practica)
# ---------------------------------------------------
add_executable(programa_principal src/main.cc)
target_link_libraries(programa_principal MiCodigo)

# ---------------------------------------------------
# 4. EJECUTABLE DE TESTS (Para hacer TDD)
# ---------------------------------------------------
add_executable(ejecutar_tests 
    test/test_instancia.cc
    test/test_solucion.cc
)

target_link_libraries(ejecutar_tests 
    MiCodigo 
    GTest::gtest_main
)

# Habilitar la integracion de tests de CMake
include(GoogleTest)
gtest_discover_tests(ejecutar_tests)