#ifndef LECTOR_INSTANCIA_H
#define LECTOR_INSTANCIA_H

#include <string>
#include "instancia.h"

/**
 * @class LectorInstancia
 * @brief Interfaz abstracta para la lectura de datos del problema.
 */
class LectorInstancia {
 public:
  /**
   * @brief Destructor virtual por defecto.
   */
  virtual ~LectorInstancia() = default;

  /**
   * @brief Lee un fichero y construye una instancia del problema.
   * @param ruta_fichero Ruta al archivo que contiene los datos.
   * @return Puntero a la Instancia generada dinámicamente.
   */
  virtual Instancia* LeerDesdeFichero(const std::string& ruta_fichero) = 0;
};

#endif