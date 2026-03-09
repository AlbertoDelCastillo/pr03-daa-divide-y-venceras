cmake_minimum_required(VERSION 3.14)
project(PracticaDivideYVenceras)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    src/algoritmo
    src/instancias
    src/solucion
    src/lector
    src
)

# Incluir el módulo de descarga de CMake
include(FetchContent)

# Declarar de donde vamos a sacar la librería JSON
FetchContent_Declare(
    json
    URL https://github.com/nlohmann/json/releases/download/v3.11.3/json.tar.xz
)

# Hacer que la librería esté disponible para nuestro proyecto
FetchContent_MakeAvailable(json)

add_library(MiCodigo 
    src/algoritmo/divideyvenceras.cc
    src/algoritmo/mergesort.cc
    src/algoritmo/quicksort.cc
    src/instancias/instancia-vector.cc
    src/instancias/instancia-empleados.cc
    src/lector/lector-json.cc
    src/solucion/solucion-vector.cc
    src/utilidades.cc
)

# Añade la ruta de los headers de nlohmann/json a MiCodigo
target_include_directories(MiCodigo PUBLIC ${nlohmann_json_SOURCE_DIR}/include)

# Primer ejecutable (primer punto)
add_executable(programa_divide-y-venceras src/cliente-divide-y-venceras.cc)

# Segundo ejecutable (segundo punto)
add_executable(cliente-empleados src/cliente-empleados.cc)

target_link_libraries(programa_divide-y-venceras PRIVATE MiCodigo)
target_link_libraries(cliente-empleados PRIVATE MiCodigo nlohmann_json::nlohmann_json)