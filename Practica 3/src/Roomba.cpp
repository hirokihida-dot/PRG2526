/**
 * @file Roomba.cpp
 * @brief Implementación de la clase Roomba.
 *
 * Este fichero contiene la implementación de los métodos de la clase Roomba,
 * que modela el comportamiento básico de un robot aspirador.
 */

#include <iostream>
#include "../Include/Roomba.h"

/**
 * @brief Constructor por defecto de la clase Roomba.
 *
 * Inicializa la Roomba con valores por defecto:
 * batería al 100%, posición (0,0), sin limpiar y sin polvo recogido.
 */
Roomba::Roomba() {
    name = "Roomba"; // Nombre por defecto
    battery = 100; // Batería al 100%
    positionX = 0;
    positionY = 0; // Posición inicial en X e Y
    cleaning = false; // No está limpiando
    collectDust = 0; // Sin polvo recogido
}

/**
 * @brief Constructor que inicializa la Roomba con un nombre.
 *
 * La Roomba comienza con batería al 100%, posición (0,0),
 * sin estar limpiando y sin polvo recogido.
 *
 * @param name_ Nombre identificativo de la Roomba.
 */
Roomba::Roomba(std::string name_) {
    name = name_; // Asignar el nombre pasado como parámetro
    battery = 100; // Batería al 100%
    positionX = 0;
    positionY = 0; // Posición inicial en X e Y
    cleaning = false; // No está limpiando
    collectDust = 0; // Sin polvo recogido
}

/**
 * @brief Constructor completo de la clase Roomba.
 *
 * Permite inicializar los atributos principales del robot.
 * El atributo limpiando debe comenzar siempre con valor false.
 *
 * @param name_ Nombre identificativo de la Roomba.
 * @param battery_ Nivel inicial de batería.
 * @param positionX_ Posición inicial en el eje X.
 * @param positionY_ Posición inicial en el eje Y.
 * @param collectedDust Cantidad inicial de polvo recogido.
 */
Roomba::Roomba(std::string name_, int battery_, int positionX_, int positionY_,
               int collectedDust_) {
    name = name_; // Asignar el nombre pasado como parámetro
    battery = battery_; // Asignar el nivel de batería pasado como parámetro
    positionX = positionX_; // Asignar la posición X pasada como parámetro
    positionY = positionY_; // Asignar la posición Y pasada como parámetro
    cleaning = false; // No está limpiando
    collectDust = collectedDust_; // Asignar la cantidad de polvo recogido pasada como parámetro
}

/**
 * @brief Mueve la Roomba en el plano.
 *
 * Modifica la posición actual del robot según los desplazamientos indicados.
 *
 * @param dx Desplazamiento en el eje X.
 * @param dy Desplazamiento en el eje Y.
 * @return Cadena con un mensaje indicando la nueva posición.
 */
std::string Roomba::move(int dx, int dy) {
    positionX += dx; // Calcular la nueva posición X
    positionY += dy; // Calcular la nueva posición Y
    return "Nueva posición: (" + std::to_string(positionX) + ", " + std::to_string(positionY) + ")"; // Devolver la nueva posición como cadena
}

/**
 * @brief Realiza una acción de limpieza.
 *
 * Si la batería es suficiente, la Roomba pasa a estado de limpieza,
 * reduce la batería y aumenta el polvo recogido.
 *
 * @return true si la limpieza ha sido exitosa, false en caso contrario.
 */
bool Roomba::clean() {
    if (battery >= 10) {
        cleaning = true;
        battery -= 10;
        collectDust += 5;
        std::cout << "La Roomba ha comenzado a limpiar." << std::endl;
        return true;
    } else {
        std::cout << "Batería insuficiente para limpiar." << std::endl;
        return false;
    }
}

/**
 * @brief Detiene la limpieza del robot.
 *
 * Cambia el estado interno del objeto para indicar que la Roomba
 * deja de estar limpiando.
 */
void Roomba::stopCleaning() {
    // TODO: Cambiar el estado limpiando a false
    cleaning = false; // Detener la limpieza

}

/**
 * @brief Recarga la batería de la Roomba.
 *
 * Establece el nivel de batería al 100%.
 */
void Roomba::recharge() {
    // TODO: Establecer la batería al 100%
    battery = 100; // Recargar la batería al 100%
}

/**
 * @brief Devuelve el estado actual de la Roomba.
 *
 * Incluye información sobre la posición, batería,
 * si está limpiando y el polvo recogido.
 *
 * @return Cadena con el estado actual del robot.
 */
std::string Roomba::getStatus() {
    // TODO: Construir y devolver una cadena con el estado de la Roomba
    return "Estado de " + name + ": \n Posición (" + std::to_string(positionX) + ", " + std::to_string(positionY) + ") \n Batería: " + std::to_string(battery) + "% \n Polvo recogido: " + std::to_string(collectDust) + " unidades " + "\n" + (cleaning ? "Limpiando" : "No limpiando"); // Devolver el estado como cadena
}