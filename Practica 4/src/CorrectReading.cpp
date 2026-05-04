#include "../include/CorrectReading.h"

#include <iostream>
#include <regex>
#include <stdexcept>

using namespace std;

/**
 * @brief Lee un valor entero desde la entrada estándar.
 *
 * La lectura se repite hasta que el usuario introduce
 * un número entero válido.
 *
 * @param msg Mensaje que se muestra al usuario antes de leer el valor.
 * @return El primer entero válido introducido por el usuario.
 */
int CorrectReading::nextInt(const string& msg) {
    string sValue;
    int value;
    bool error = true;

    do {
        try {
            cout << msg;
            cin >> sValue;

            if (!regex_match(sValue, regex("^[+-]?[0-9]+$"))) {
                throw invalid_argument("Please enter a valid integer number.");
            }

            value = stoi(sValue);
            error = false;
        }
        catch (const invalid_argument& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    } while (error);

    return value;
}

/**
 * @brief Lee un valor real (double) desde la entrada estándar.
 *
 * La lectura se repite hasta que el usuario introduce
 * un número real válido con parte decimal.
 *
 * @param msg Mensaje que se muestra al usuario antes de leer el valor.
 * @return El primer número real válido introducido por el usuario.
 */
double CorrectReading::nextDouble(const string& msg) {
    string sValue;
    double value;
    bool error = true;

    do {
        try {
            cout << msg;
            cin >> sValue;

            if (!regex_match(sValue, regex("^[+-]?[0-9]+\\.[0-9]+$"))) {
                throw invalid_argument("Please enter a valid real number.");
            }

            value = stod(sValue);
            error = false;
        }
        catch (const invalid_argument& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    } while (error);

    return value;
}

/**
 * @brief Lee un valor real (double) no negativo desde la entrada estándar.
 *
 * Lee un valor desde la entrada de teclado y devuelve el primer número
 * real no negativo introducido correctamente.
 *
 * Si el valor leído no es un número real válido, se lanza una excepción
 * de tipo std::invalid_argument con el mensaje:
 * "Por favor, introduzca un numero real ... ".
 *
 * Si el valor leído es un número real negativo, se lanza una excepción
 * de tipo std::out_of_range con el mensaje:
 * "Por favor, introduzca un número real positivo ... ".
 *
 * La lectura se repite hasta que el usuario introduce un valor correcto,
 * devolviendo el primero que sea mayor o igual que 0.0.
 *
 * @param msg Mensaje que se muestra al usuario antes de leer el valor.
 * @return El primer número real no negativo válido introducido por el usuario.
 */
double CorrectReading::nextDoublePositive(const string& msg) {
    
    // ESTE CÓDIGO NO ES SEGURO:
    // MODIFICAR PARA QUE LANCE Y CAPTURE LAS EXCEPCIONES INDICADAS EN LA CABECERA
    // DE LA FUNCIÓN, CUMPLIENDO CON LOS REQUISITOS DE FUNCIONALIDAD ESTABLECIDOS.
    
    string sValue;
    double value = 0.0;
    bool error = true;
    
    do{

        try{
            cout << msg;
            cin >> sValue;
            if (!regex_match(sValue, regex("^[+-]?[0-9]+\\.[0-9]+$"))) {
                throw invalid_argument("Please enter a valid real number.");            
            }
            if (stod(sValue) < 0.0) {
                throw out_of_range("Please enter a positive real number.");
            }
            value = stod(sValue);
            error = false;
        }
        catch (const invalid_argument& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    } while(error);

    

    return value;
}

/**
 * @brief Lee un valor entero dentro de un rango dado.
 *
 * Lee un valor desde la entrada de teclado y devuelve el primero que
 * sea de tipo entero y esté dentro del rango delimitado por
 * [lowerBound, upperBound].
 *
 * Si el valor leído no es un entero válido, se lanza una excepción
 * de tipo std::invalid_argument con el mensaje:
 * "Por favor, introduzca un numero entero correcto ... ".
 *
 * Si el entero leído está fuera del rango especificado, se lanza una
 * excepción de tipo std::out_of_range con el mensaje:
 * "v no está en el rango [lowerBound, upperBound]",
 * donde v es el valor leído, y lowerBound y upperBound son los
 * límites del intervalo.
 *
 * La lectura se repite hasta que el usuario introduce un valor correcto,
 * devolviendo el primero que sea un entero válido dentro del rango.
 *
 * @param msg Mensaje que se muestra al usuario antes de leer el valor.
 * @param lowerBound Límite inferior del intervalo válido.
 * @param upperBound Límite superior del intervalo válido.
 * @return El primer entero válido dentro del intervalo especificado.
 */
int CorrectReading::nextInt(const string& msg, int lowerBound, int upperBound) {
	
    // ESTE CÓDIGO NO ES SEGURO:
    // MODIFICAR PARA QUE LANCE Y CAPTURE LAS EXCEPCIONES INDICADAS EN LA CABECERA
    // DE LA FUNCIÓN, CUMPLIENDO CON LOS REQUISITOS DE FUNCIONALIDAD ESTABLECIDOS.
	
    string sValue;
    int value;
    bool error = true;
    
    do{
        try{
            cout << msg;
            cin >> sValue;

            if (!regex_match(sValue, regex("^[+-]?[0-9]+$"))) {
                throw invalid_argument("Please enter a valid integer number.");            
            }
            if (stoi(sValue) < lowerBound || stoi(sValue) > upperBound) {
                throw out_of_range("Value is not in the range [" + to_string(lowerBound) + ", " + to_string(upperBound) + "].");
            }
            value = stoi(sValue);
            error = false;
        }
        catch (const invalid_argument& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
        catch (const out_of_range& e) {
            cout << "Exception caught: " << e.what() << endl;
        }
    } while(error);
    
    return value;
}