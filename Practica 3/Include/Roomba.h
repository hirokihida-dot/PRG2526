#ifndef ROOMBA_H
#define ROOMBA_H

#include <string>

class Roomba {
private:
// Atributos
    std::string name;     // Nombre identificador del robot

    int battery;  //nivel de batería del robot

    int positionX, positionY; //posición en el eje X e Y del robot

    bool cleaning; //Indica si el robot está limpiando o no

    int collectDust; //Cantidad de polvo recogido por el robot

public:
    // Constructores
    Roomba(); // Constructor por defecto

    Roomba(std::string name); // Constructor con nombre

    Roomba(std::string name, int battery, int positionX, int positionY, int collectDust); // Constructor con nombre y batería

    std::string move (int dx, int dy); // Método para actualizar la posición del robot, dx y dy representan el cambio en las coordenadas X e Y respectivamente

    bool clean(); // Método para iniciar la limpiezar. Devuelve true si el robot comenzó a limpiar, false si no pudo iniciar la limpieza (por ejemplo, si la batería está baja).

    void recharge(); // Método para recargar la batería del robot a su nivel máximo.

    std::string getStatus(); // Método para obtener el estado actual del robot, incluyendo su posición, nivel de batería, cantidad de polvo recogido y si está limpiando o no.

    void stopCleaning(); // Método para detener la limpieza del robot.    

        
};

#endif