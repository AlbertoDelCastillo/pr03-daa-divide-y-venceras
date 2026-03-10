#ifndef LECTOR_JSON_H
#define LECTOR_JSON_H

#include <string>
#include "lector-instancia.h"
#include "instancia-empleados.h"

/**
 * @class LectorJSON
 * @brief Clase concreta que implementa la lectura de instancias desde archivos JSON.
 */
class LectorJSON : public LectorInstancia {
 public:
  /**
   * @brief Constructor por defecto.
   */
  LectorJSON() = default;

  /**
   * @brief Destructor por defecto.
   */
  ~LectorJSON() = default;

  /**
   * @brief Lee un fichero JSON y construye una InstanciaEmpleados.
   * @param ruta_fichero Ruta al archivo .json.
   * @return Puntero a la Instancia generada.
   */
  Instancia* LeerDesdeFichero(const std::string& ruta_fichero) override;
};

#endif