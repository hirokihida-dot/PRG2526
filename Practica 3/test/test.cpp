#include <iostream>
#include "../Include/Roomba.h"

int main() {

    // 1. Crear dos objetos Roomba estáticos con nombres distintossadasdadaaaaa
    // TODO
    Roomba roomba1("Rd2d2");
    Roomba roomba2("c3po");


    // 2. Mostrar el estado actual del primer objeto
    // TODO
    std::cout << "Estado del primer robot: " << roomba1.getStatus() << std::endl; // Mostrar el estado del primer robot

    // 3. Hacer que el primer objeto se mueva y limpie
    // TODO: llamar a mover y limpiar
    // TODO: mostrar por pantalla si la limpieza fue exitosa o no
    std::cout << roomba1.move(5, 3) << std::endl; // Mover el primer robot
    if (roomba1.clean()) { // Intentar limpiar con el primer robot
        std::cout << "Limpieza exitosa." << std::endl; // Limpieza exitosa
    } else {    
        std::cout << "Limpieza no iniciada." << std::endl; // Limpieza no iniciada
    }

    // 4. Mostrar el estado del primer robot
	// TODO

    roomba1.getStatus(); // Mostrar el estado del primer robot después de mover y limpiar

    // 5. Hacer que el primer objeto deje de limpiar
    // TODO: llamar a pararLimpieza()
    roomba1.stopCleaning(); // Detener la limpieza del primer robot

    // 6. Recargar el primer objeto
    // TODO: llamar a recargar()
    roomba1.recharge(); // Recargar la batería del primer robot

    // 7. Repetir las mismas acciones para el segundo objeto
    // TODO
    std::cout << "Estado del segundo robot: " << roomba2.getStatus() << std::endl; // Mostrar el estado del segundo robot
    std::cout << roomba2.move(2, 4) << std::endl; // Mover el segundo robot
    if (roomba2.clean()) { // Intentar limpiar con el segundo robot
        std::cout << "Limpieza exitosa." << std::endl; // Limpieza exitosa
    } else {    
        std::cout << "Limpieza no iniciada." << std::endl; // Limpieza no iniciada
    }
    roomba2.getStatus(); // Mostrar el estado del segundo robot después de mover y limpiar
    roomba2.stopCleaning(); // Detener la limpieza del segundo robot
    roomba2.recharge(); // Recargar la batería del segundo robot

    // 8. Crear un objeto Roomba dinámico con un nombre distinto
    // TODO
    Roomba* roomba3 = new Roomba("Dalek"); // Crear un tercer robot dinámico

    // 9. Mostrar el estado actual del tercer objeto
 	// TODO
    std::cout << "Estado del tercer robot: " << roomba3->getStatus() << std::endl; // Mostrar el estado del tercer robot

    // 10. Mover y limpiar el tercer objeto
    // TODO
    std::cout << roomba3->move(1, 1) << std::endl; // Mover el tercer robot
    if (roomba3->clean()) { // Intentar limpiar con el tercer robot
        std::cout << "Limpieza exitosa." << std::endl; // Limp  ieza exitosa
    } else {    
        std::cout << "Limpieza no iniciada." << std::endl; // Limpieza no iniciada
    }
    

    // 11. Parar limpieza, recargar y mostrar estado final
    // TODO
    roomba3->stopCleaning(); // Detener la limpieza del tercer robot
    roomba3->recharge(); // Recargar la batería del tercer robot
    roomba3->getStatus(); // Mostrar el estado del tercer robot después de limpiar

    // 12. Liberar la memoria del tercer objeto
    // TODO
    delete roomba3; // Liberar la memoria del tercer robot

    return 0;
}