/**
 * @file SortedRegister.cpp
 * @brief Implementación de la clase SortedRegister.
 *
 * Este fichero contiene la implementación de los métodos de la clase
 * SortedRegister, encargada de registrar, clasificar y almacenar
 * datos asociados a fechas (día y mes) de un año concreto.
 */

#include "../include/SortedRegister.h"

#include <iostream>
#include <sstream>
#include <stdexcept>

using namespace std;

/**
 * @brief Número de días de cada mes (índice 1–12).
 *
 * La posición 0 no se utiliza. Febrero se ajusta en función
 * de si el año es bisiesto.
 */
const int SortedRegister::DAYS[13] =
{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

/**
 * @brief Comprueba si un año es bisiesto.
 *
 * @param year Año a comprobar.
 * @return true si el año es bisiesto, false en caso contrario.
 */
bool SortedRegister::isLeap(int year) const {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

/**
 * @brief Constructor de la clase SortedRegister.
 *
 * Reserva memoria para almacenar los datos correspondientes
 * a todos los días válidos del año indicado, inicializando
 * los valores a cero.
 *
 * @param year Año para el que se crea el registro.
 */
SortedRegister::SortedRegister(int year) : year(year) {

    bool leap = isLeap(year);
    registerMatrix = new int*[13];

    for (int month = 1; month <= 12; month++) {
        int numDays = DAYS[month];
        if (month == 2 && leap) {
            numDays++;
        }

        registerMatrix[month] = new int[numDays + 1];
        for (int day = 1; day <= numDays; day++) {
            registerMatrix[month][day] = 0;
        }
    }
}

/**
 * @brief Destructor de la clase SortedRegister.
 *
 * Libera toda la memoria dinámica reservada para la matriz
 * de registro.
 */
SortedRegister::~SortedRegister() {
    for (int month = 1; month <= 12; month++) {
        delete[] registerMatrix[month];
    }
    delete[] registerMatrix;
}

/**
 * @brief Procesa una línea de datos del fichero de entrada.
 *
 * La línea debe contener tres valores: día, mes y cantidad.
 * Si los datos no son correctos (formato incorrecto, fecha
 * no válida o cantidad negativa), se lanza una excepción.
 *
 * @param line Línea de texto a procesar.
 * @throw std::invalid_argument si la línea es incorrecta.
 */
void SortedRegister::handleLine(const string& line) {

    istringstream iss(line);
    string data[3];

    for (int i = 0; i < 3; i++) {
        if (!(iss >> data[i])) {
            throw invalid_argument("La línea no contiene tres datos.");
        }
    }
	
    // Comprobar que NO hay más datos
    string extra;
    if (iss >> extra) {
        throw invalid_argument("La línea contiene más de tres datos.");
    }

    int day = stoi(data[0]);
    int month = stoi(data[1]);
    int amount = stoi(data[2]);

    if (month < 1 || month > 12) {
        throw invalid_argument("Mes incorrecto.");
    }

    int maxDay = DAYS[month];
    if (month == 2 && isLeap(year)) {
        maxDay++;
    }

    if (day < 1 || day > maxDay) {
        throw invalid_argument("Día incorrecto.");
    }

    if (amount < 0) {
        throw invalid_argument("Número de incidencias negativo.");
    }

    registerMatrix[month][day] += amount;
}

/**
 * @brief Procesa un fichero de entrada completo.
 *
 * Si se detecta un error en alguna línea, el proceso se interrumpe,
 * se muestra un mensaje de error por pantalla y se devuelve -1.
 *
 * @param input Fichero de entrada con los datos.
 * @return Número de líneas procesadas o -1 si se produce un error.
 */
int SortedRegister::add(ifstream& input) {
    //COMPLETAR CON LA CAPTURA DE EXCEPCIONES
    string line;
    int lineCount = 0;
    try {
        while (getline(input, line)) {
            lineCount++;
            handleLine(line);
        }
    } catch (const invalid_argument& e) {
            cout << "Error en línea " << lineCount << ": " << e.what() << endl;
            lineCount = -1;
        }

    return lineCount;
}

/**
 * @brief Procesa un fichero de entrada generando un informe de errores.
 *
 * Las líneas incorrectas no se procesan y se registran en el fichero
 * de errores indicado, permitiendo continuar con el resto de datos.
 *
 * @param input Fichero de entrada con los datos.
 * @param log Fichero de salida para el informe de errores.
 * @return Número total de líneas procesadas.
 */
int SortedRegister::add(ifstream& input, ofstream& log) {
    //COMPLETAR CON LA CAPTURA DE EXCEPCIONES
    string line;
    int lineCount = 0;

    while (getline(input, line)) {
        lineCount++;
        try {handleLine(line);
        } catch (const invalid_argument& e) {
                log << "Error en línea " << lineCount << ": " << e.what() << endl;
        }
    }

    return lineCount;
}

/**
 * @brief Guarda los datos acumulados en un fichero de salida.
 *
 * Solo se escriben aquellos días cuya cantidad acumulada es mayor que cero.
 * Los datos se escriben ordenados cronológicamente por mes y día.
 *
 * @param output Fichero de salida donde se escriben los datos.
 */
void SortedRegister::save(ofstream& output) const {

    bool leap = isLeap(year);

    for (int month = 1; month <= 12; month++) {
        int maxDay = DAYS[month];
        if (month == 2 && leap) {
            maxDay++;
        }

        for (int day = 1; day <= maxDay; day++) {
            int amount = registerMatrix[month][day];
            if (amount > 0) {
                output << day << " " << month << " " << amount << endl;
            }
        }
    }
}