#include <iostream>
#include <fstream>
#include <string>

#include "../include/CorrectReading.h"
#include "../include/SortedRegister.h"

using namespace std;

/* Función de prueba de los métodos add(ifstream&) y save(ofstream&)
 * de la clase SortedRegister. Procesa los datos que se leen del
 * fichero de entrada de datos.
 *
 * Los datos procesados se guardan en el fichero de salida
 * con extensión .out.
 *
 * Si se encuentra algun error en los datos de entrada,
 * el proceso termina y out queda vacio.
 *
 * year año de los datos.
 * ficheroEntrada fuente de los datos.
 * ficheroSalida destino de los datos procesados.
 */
void test1(int year, ifstream& ficheroEntrada, ofstream& ficheroSalida) {

    SortedRegister reg(year);

    int n = reg.add(ficheroEntrada);

    if (n > 0) {
        reg.save(ficheroSalida);
        cout << "Se han procesado " << n << " líneas." << endl;
    } else {
        cout << "El fichero de resultados ha quedado vacío." << endl;
    }

    cout << "----------------------------------------------------" << endl;
    cout << "test1 finalizado." << endl;
    cout << "----------------------------------------------------" << endl;
}

/* Función de prueba de los métodos add(ifstream&, ofstream&) y
 * save(ofstream&) de la clase SortedRegister. Procesa los datos que
 * se leen del fichero de entrada.
 *
 * Los datos procesados se guardan en el fichero de salida .out.
 * Si se encuentra algun dato erroneo, se ignora:
 * sus datos no se procesan y en err se registra el numero de linea
 * y el error encontrado.
 *
 * year año de los datos.
 * ficheroEntrada fuente de los datos.
 * ficheroSalida destino de los datos procesados.
 * err destino del informe de errores.
 */
void test2(int year, ifstream& ficheroEntrada,
           ofstream& ficheroSalida, ofstream& err) {

    
    SortedRegister reg(year);

    int n = reg.add(ficheroEntrada, err);

    if (n > 0) {
        reg.save(ficheroSalida);
        cout << "Se han procesado " << n << " líneas." << endl;
    } else {
        cout << "El fichero de resultados ha quedado vacío." << endl;
    }

    cout << "----------------------------------------------------" << endl;
    cout << "test2 finalizado." << endl;
    cout << "----------------------------------------------------" << endl;
}



int main() {

    int currentY = 2026;
    string msg = "Introduzca un número de año (hasta diez años atrás): ";
    int year = CorrectReading::nextInt(msg, currentY - 10, currentY);
    cout << "Nombre del fichero a clasificar: " << endl;
    string nameIn;
    cin >> nameIn;
    
    ifstream ficheroEntrada;
    ofstream ficheroSalida;
    ofstream ficheroLog;
    
    string nombreFicheroEntrada = "data/"+ nameIn + ".txt";
    ficheroEntrada.open(nombreFicheroEntrada, ifstream::in);
        
    string nombreFicheroSalida = "data/"+ nameIn + ".out";
    ficheroSalida.open(nombreFicheroSalida, ofstream::out);

    string nombreFicheroLog = "data/"+ nameIn + ".log";
    ficheroLog.open(nombreFicheroLog, ofstream::out);
        
    msg = "Opciones de clasificación: \n1.- test1.\n2.- test2.\n? ";
    int option = CorrectReading::nextInt(msg, 1, 2);
    switch (option) {
            case 1:
                test1(year, ficheroEntrada, ficheroSalida);
                break;
            case 2:
                test2(year, ficheroEntrada, ficheroSalida, ficheroLog);
                break;
    }

    ficheroEntrada.close();
    ficheroSalida.close();
    ficheroLog.close();
    return 0;
}