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
 * @file utilidades.cc
 * @brief Funciones auxiliares para la experimentación y comparación de algoritmos de ordenación
 *        mediante la metodología Divide y Vencerás (MergeSort y QuickSort).
 * @date Mar 8 2026
 * @version 1.0
 */

#include "utilidades.h"

/**
 * @brief Ejecuta el modo empleados usando fábrica y configuración externa.
 *
 * Solicita dos ficheros JSON: uno con la instancia del problema y otro con
 * la configuración del algoritmo. Después construye el algoritmo mediante
 * FabricaAlgoritmos, resuelve la instancia y muestra la solución.
 */
void ModoEmpleados(const std::string& ruta_instancia, const std::string& ruta_algoritmo) {
  LectorInstancia* lector_instancia = new LectorJSON();
  LectorConfiguracion* lector_configuracion = new LectorConfiguracionJSON();
  Instancia* problema = lector_instancia->LeerDesdeFichero(ruta_instancia);
  if (problema == nullptr) {
    std::cerr << "Fallo al cargar la instancia." << std::endl;
    delete lector_instancia;
    delete lector_configuracion;
    return;
  }
  ConfiguracionAlgoritmo config =
      lector_configuracion->LeerFichero(ruta_algoritmo);
  FabricaAlgoritmos fabrica;
  Algoritmo* algoritmo = nullptr;
  try {
    algoritmo = fabrica.CrearAlgoritmo(config, problema);
  } catch (const std::exception& e) {
    std::cerr << "Error al crear el algoritmo: " << e.what() << std::endl;
    delete problema;
    delete lector_instancia;
    delete lector_configuracion;
    return;
  }
  if (algoritmo == nullptr) {
    std::cerr << "No se pudo crear el algoritmo." << std::endl;
    delete problema;
    delete lector_instancia;
    delete lector_configuracion;
    return;
  }
  PlanificacionEmpleados* planificacion =
      dynamic_cast<PlanificacionEmpleados*>(algoritmo);
  if (planificacion == nullptr) {
    std::cerr << "El algoritmo creado no es un planificador de empleados." << std::endl;
    delete algoritmo;
    delete problema;
    delete lector_instancia;
    delete lector_configuracion;
    return;
  }
  Solucion* solucion = planificacion->Solve(problema);
  solucion->Mostrar();
  InstanciaEmpleados* problema_empleados =
      dynamic_cast<InstanciaEmpleados*>(problema);
  if (problema_empleados != nullptr) {
    planificacion->MostrarCobertura(solucion, problema_empleados);
  }
  delete solucion;
  delete algoritmo;
  delete problema;
  delete lector_instancia;
  delete lector_configuracion;
}

/**
 * @brief Parsea los argumentos de línea de comandos sin usar getopt.
 *
 * Recorre argv buscando flags con prefijo '-'. Las flags que esperan
 * valor (-i, -a) leen el siguiente elemento de argv como su argumento.
 *
 * @param argc Número de argumentos.
 * @param argv Vector de argumentos.
 * @return Argumentos con los campos rellenos según lo recibido.
 */
Argumentos ParsearArgumentos(int argc, char* argv[]) {
  Argumentos args;
  for (int i = 1; i < argc; ++i) {
    std::string flag = argv[i];
    if (flag == "-i") {
      if (i + 1 >= argc) {
        args.error = true;
        args.mensaje_error = "-i requiere una ruta como argumento";
        return args;
      }
      args.ruta_instancia = argv[++i];
    } else if (flag == "-a") {
      if (i + 1 >= argc) {
        args.error = true;
        args.mensaje_error = "-a requiere una ruta como argumento";
        return args;
      }
      args.ruta_algoritmo = argv[++i];
    } else if (flag == "-e") {
      args.modo_experimentacion = true;
    } else if (flag == "-h") {
      args.mostrar_ayuda = true;
    } else {
      args.error = true;
      args.mensaje_error = "Opcion no reconocida: " + flag;
      return args;
    }
  }
  return args;
}

/**
 * @brief Muestra el mensaje de ayuda con el uso del programa.
 * @param nombre_programa Nombre del ejecutable (argv[0]).
 */
void MostrarAyuda(const std::string& nombre_programa) {
  std::cout << "Uso: " << nombre_programa << " [opciones]\n\n"
            << "Opciones:\n"
            << "  -i <ruta>   Ruta al JSON de instancia de empleados\n"
            << "  -a <ruta>   Ruta al JSON de configuracion del algoritmo\n"
            << "  -e          Modo experimentacion: ejecuta todas las instancias\n"
            << "              de test con PD y Greedy y muestra la tabla comparativa\n"
            << "  -h          Muestra este mensaje de ayuda\n\n"
            << "Ejemplos:\n"
            << "  " << nombre_programa << " -i instancia.json -a algoritmo.json\n"
            << "  " << nombre_programa << " -e\n";
}

/**
 * @brief Muestra la tabla comparativa del enunciado con los resultados
 *        de PD y Greedy para cada instancia.
 *
 * @param resultados_pd     Vector de resultados del algoritmo de PD.
 * @param resultados_greedy Vector de resultados del algoritmo Greedy.
 */
void MostrarTablaComparativa(const std::vector<ResultadoExperimento>& resultados_pd,
                             const std::vector<ResultadoExperimento>& resultados_greedy) {
  const int w1 = 10, w2 = 6, w3 = 8, w4 = 12, w5 = 18, w6 = 13, w7 = 14;
  std::cout << "\n"
            << std::setw(w1) << "Empleados"
            << std::setw(w2) << "Dias"
            << std::setw(w3) << "Turnos"
            << std::setw(w4) << "Valor PD"
            << std::setw(w5) << "Tiempo PD (ms)"
            << std::setw(w6) << "Valor Voraz"
            << std::setw(w7) << "T. Voraz (ms)"
            << "\n";
  std::cout << std::string(w1+w2+w3+w4+w5+w6+w7, '-') << "\n";
  for (size_t i = 0; i < resultados_pd.size(); ++i) {
    const auto& pd = resultados_pd[i];
    const auto& gr = resultados_greedy[i];
    std::cout << std::setw(w1) << pd.empleados
              << std::setw(w2) << pd.dias
              << std::setw(w3) << pd.turnos
              << std::setw(w4) << pd.valor
              << std::setw(w5) << std::fixed << std::setprecision(2) << pd.tiempo_ms
              << std::setw(w6) << gr.valor
              << std::setw(w7) << std::fixed << std::setprecision(2) << gr.tiempo_ms
              << "\n";
  }
  std::cout << "\n";
}

/**
 * @brief Ejecuta un algoritmo sobre una instancia y devuelve el resultado.
 *
 * Función auxiliar interna que encapsula la creación del algoritmo via
 * fábrica, la resolución y la medición del tiempo de ejecución.
 *
 * @param ruta_instancia Ruta al JSON de la instancia.
 * @param ruta_algoritmo Ruta al JSON de configuración del algoritmo.
 * @return ResultadoExperimento con valor objetivo y tiempo, o {-1} si falla.
 */
static ResultadoExperimento EjecutarAlgoritmo(const std::string& ruta_instancia,
                                               const std::string& ruta_algoritmo) {
  LectorInstancia* lector_instancia = new LectorJSON();
  LectorConfiguracion* lector_config = new LectorConfiguracionJSON();
  Instancia* problema = lector_instancia->LeerDesdeFichero(ruta_instancia);
  if (problema == nullptr) {
    delete lector_instancia;
    delete lector_config;
    return {-1, -1, -1, -1, -1.0};
  }
  ConfiguracionAlgoritmo config = lector_config->LeerFichero(ruta_algoritmo);
  FabricaAlgoritmos fabrica;
  Algoritmo* algoritmo = nullptr;
  try {
    algoritmo = fabrica.CrearAlgoritmo(config, problema);
  } catch (const std::exception& e) {
    std::cerr << "Error al crear el algoritmo: " << e.what() << "\n";
    delete problema;
    delete lector_instancia;
    delete lector_config;
    return {-1, -1, -1, -1, -1.0};
  }
  PlanificacionEmpleados* planificacion =
      dynamic_cast<PlanificacionEmpleados*>(algoritmo);
  if (planificacion == nullptr) {
    delete algoritmo;
    delete problema;
    delete lector_instancia;
    delete lector_config;
    return {-1, -1, -1, -1, -1.0};
  }
  auto inicio = std::chrono::high_resolution_clock::now();
  Solucion* solucion = planificacion->Solve(problema);
  auto fin = std::chrono::high_resolution_clock::now();
  double tiempo_ms = std::chrono::duration<double, std::milli>(fin - inicio).count();
  InstanciaEmpleados* inst_emp = dynamic_cast<InstanciaEmpleados*>(problema);
  SolucionEmpleados* sol_emp   = dynamic_cast<SolucionEmpleados*>(solucion);
  ResultadoExperimento resultado;
  resultado.empleados = inst_emp ? inst_emp->GetNumEmpleados()   : -1;
  resultado.dias      = inst_emp ? inst_emp->GetNumDias()        : -1;
  resultado.turnos    = inst_emp ? inst_emp->GetNumTurnos()      : -1;
  resultado.valor     = sol_emp  ? sol_emp->GetValorObjetivo()   : -1;
  resultado.tiempo_ms = tiempo_ms;
  delete solucion;
  delete algoritmo;
  delete problema;
  delete lector_instancia;
  delete lector_config;
  return resultado;
}

/**
 * @brief Modo experimentación: ejecuta todas las instancias de test con
 *        PD y Greedy y muestra la tabla comparativa del enunciado.
 *
 * Las rutas a las instancias y algoritmos están fijadas respecto al
 * directorio de trabajo esperado (raíz del repositorio).
 */
void ModoExperimentacion() {
  const std::vector<std::string> instancias = {
    "../test-empleados/instance_horizon7_employees5_shifts3_000.json",
    "../test-empleados/instance_horizon7_employees5_shifts3_001.json",
    "../test-empleados/instance_horizon7_employees10_shifts6_000.json",
    "../test-empleados/instance_horizon7_employees10_shifts6_001.json",
    "../test-empleados/instance_horizon14_employees10_shifts6_000.json",
    "../test-empleados/instance_horizon14_employees10_shifts6_001.json",
    "../test-empleados/instance_horizon14_employees20_shifts10_000.json",
    "../test-empleados/instance_horizon14_employees20_shifts10_001.json",
    "../test-empleados/instance_horizon30_employees20_shifts10_000.json",
    "../test-empleados/instance_horizon30_employees20_shifts10_001.json",
    "../test-empleados/instance_horizon30_employees30_shifts20_000.json",
    "../test-empleados/instance_horizon30_employees30_shifts20_001.json",
  };
  const std::string config_pd     = "../test-algoritmos/divide_and_dynamic.json";
  const std::string config_greedy = "../test-algoritmos/divide_and_greedy.json";
  std::vector<ResultadoExperimento> resultados_pd;
  std::vector<ResultadoExperimento> resultados_greedy;
  std::cout << "Ejecutando experimentacion...\n";
  for (const auto& instancia : instancias) {
    std::cout << "  " << instancia << "\n";
    resultados_pd.push_back(EjecutarAlgoritmo(instancia, config_pd));
    resultados_greedy.push_back(EjecutarAlgoritmo(instancia, config_greedy));
  }
  MostrarTablaComparativa(resultados_pd, resultados_greedy);
}