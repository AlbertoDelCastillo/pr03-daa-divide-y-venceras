#include <iostream>
#include <string>

#include "lector-json.h"
#include "instancia-empleados.h"

int main() {
  std::cout << "Iniciando prueba de lectura JSON..." << std::endl;
  std::string ruta_archivo = "../test/test1.json"; 
  LectorInstancia* lector = new LectorJSON();
  Instancia* problema_empleados = lector->LeerDesdeFichero(ruta_archivo);
  if (problema_empleados != nullptr) {
    std::cout << "¡Lectura exitosa! Mostrando datos extraidos:" << std::endl;
    problema_empleados->Mostrar();
    delete problema_empleados;
  } else {
    std::cerr << "Fallo al cargar la instancia. Revisa la ruta y el formato del JSON." << std::endl;
  }
  delete lector;
  return 0;
}