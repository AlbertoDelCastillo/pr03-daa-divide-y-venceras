#ifndef LECTOR_CONFIGURACION_H
#define LECTOR_CONFIGURACION_H

#include <string>
#include "configuracion-algoritmo.h"

/**
 * @class LectorConfiguracion
 * @brief Interfaz abstracta para leer ficheros de configuración.
 */
class LectorConfiguracion {
public:
    virtual ~LectorConfiguracion() = default;

    /**
     * @brief Lee un fichero y devuelve un objeto con la configuración.
     * @param ruta Ruta al archivo de configuración.
     * @return Objeto ConfiguracionAlgoritmo relleno con los datos.
     */
    virtual ConfiguracionAlgoritmo LeerFichero(const std::string& ruta) = 0;
};

#endif