#ifndef CORRECTREADING_H
#define CORRECTREADING_H

#include <string>

/**
 * @class CorrectReading
 * @brief Clase utilitaria para la lectura robusta y validada por teclado.
 *
 * Esta clase proporciona métodos estáticos para leer valores enteros
 * y reales desde la entrada estándar, repitiendo la lectura hasta que
 * el valor introducido cumpla el formato y las restricciones requeridas.
 *
 * La clase no mantiene estado interno y no está pensada para ser instanciada.
 */
class CorrectReading {
public:

    /**
     * @brief Lee un valor entero desde la entrada estándar.
     *
     * La lectura se repite hasta que el usuario introduce
     * un número entero válido.
     *
     * @param msg Mensaje que se muestra al usuario antes de leer el valor.
     * @return El primer entero válido introducido por el usuario.
     */
    static int nextInt(const std::string& msg);

    /**
     * @brief Lee un valor real (double) desde la entrada estándar.
     *
     * La lectura se repite hasta que el usuario introduce
     * un número real válido con parte decimal.
     *
     * @param msg Mensaje que se muestra al usuario antes de leer el valor.
     * @return El primer número real válido introducido por el usuario.
     */
    static double nextDouble(const std::string& msg);

    /**
     * @brief Lee un valor real (double) no negativo desde la entrada estándar.
     *
     * La lectura se repite hasta que el usuario introduce
     * un número real mayor o igual que cero.
     *
     * @param msg Mensaje que se muestra al usuario antes de leer el valor.
     * @return El primer número real no negativo válido introducido por el usuario.
     */
    static double nextDoublePositive(const std::string& msg);

    /**
     * @brief Lee un valor entero dentro de un rango dado.
     *
     * La lectura se repite hasta que el usuario introduce
     * un número entero válido dentro del intervalo [lowerBound, upperBound].
     *
     * @param msg Mensaje que se muestra al usuario antes de leer el valor.
     * @param lowerBound Límite inferior del intervalo válido.
     * @param upperBound Límite superior del intervalo válido.
     * @return El primer entero válido dentro del intervalo especificado.
     */
    static int nextInt(const std::string& msg, int lowerBound, int upperBound);
};

#endif