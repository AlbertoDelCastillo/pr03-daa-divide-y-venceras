#ifndef LECTOR_CONFIGURACION_JSON_H
#define LECTOR_CONFIGURACION_JSON_H

#include "lector-configuracion.h"

/**
 * @class LectorConfiguracionJSON
 * @brief Implementación concreta para leer configuraciones desde archivos JSON.
 */
class LectorConfiguracionJSON : public LectorConfiguracion {
public:
    ConfiguracionAlgoritmo LeerFichero(const std::string& ruta) override;
};

#endif