cmake_minimum_required(VERSION 3.14)
project(PracticaDivideYVenceras)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(
    src/algoritmo
    src/algoritmo/small-solver
    src/config
    src/fabrica
    src/instancias
    src/solucion
    src/lector
    src/empleados
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
    src/algoritmo/small-solver/solver-gready.cc
    src/algoritmo/small-solver/solver-pd.cc
    src/algoritmo/small-solver/solver-greedy-mejorado.cc
    src/config/configuracion-algoritmo.cc
    src/fabrica/fabrica-algoritmo.cc
    src/instancias/instancia-empleados.cc
    src/lector/lector-configuracion-json.cc
    src/lector/lector-json.cc
    src/solucion/solucion-empleados.cc
    src/empleados/planificacion-empleados.cc
    src/utilidades.cc
)

# Añade la ruta de los headers de nlohmann/json a MiCodigo
target_include_directories(MiCodigo PUBLIC ${nlohmann_json_SOURCE_DIR}/include)

# Primer ejecutable (primer punto)
add_executable(programacion-empleados src/main.cc)


target_link_libraries(programacion-empleados PRIVATE MiCodigo)
target_include_directories(programacion-empleados PRIVATE src/empleados src/lector src/instancias src/solucion)
target_include_directories(MiCodigo PUBLIC ${nlohmann_json_SOURCE_DIR}/include src/empleados src/lector)