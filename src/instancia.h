#ifndef INSTANCIA_H
#define INSTANCIA_H

/**
 * Clase abstracta que almacena los datos de entrada del algoritmo.
 * Sus subclases se encargan de definir los metodos para instanciar y mostrar
 * lso datos.
 */
class Instancia {
 public:
  /**
   * Metodo virtual para instanciar de forma aleatoria los datos
   */
  virtual void GenerarAleatorio() = 0;

  /**
   * Metodo virtual para mostrar los valores de la instancia
   */
  virtual void Mostrar() = 0;

  /**
   * Destructor
   */
  virtual ~Instancia() = default;
};

#endif