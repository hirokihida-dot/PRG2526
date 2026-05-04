#include <iostream>
#include <string>
#include "../include/CorrectReading.h"

using namespace std;

int main() {

    cout << endl
         << "NOTA: puedes salir del test en cualquier momento pulsando Ctrl+C"
         << endl << endl;

    cout << "*************************" << endl;
    cout << "Test de lectura de enteros" << endl;
    cout << "(Actividad 2)" << endl;
    cout << "*************************" << endl;

    string msg;
    int intValue;

    msg = "\n--> Introduce varios valores inválidos "
          "(por ejemplo: hola, 3.5) y finalmente uno válido "
          "(por ejemplo: 5, +5, -5).\n";

    intValue = CorrectReading::nextInt(msg);

    cout << "Valor leído: " << intValue << endl << endl;


    cout << "*************************" << endl;
    cout << "Test de lectura de números reales" << endl;
    cout << "(Actividad 2)" << endl;
    cout << "*************************" << endl;

    double realValue;

    msg = "\n--> Introduce varios valores inválidos "
          "(por ejemplo: hola, -1, 4) y finalmente uno válido "
          "(por ejemplo: 1.1, -2.3, +3.7).\n";

    realValue = CorrectReading::nextDouble(msg);

    cout << "Valor leído: " << realValue << endl << endl;


    cout << "*************************************" << endl;
    cout << "Test de lectura de números reales positivos" << endl;
    cout << "(Actividad 3)" << endl;
    cout << "*************************************" << endl;

    msg = "\n--> Introduce varios valores inválidos "
          "(por ejemplo: hola, 4, -1.4) y finalmente uno válido "
          "(por ejemplo: 1.1, +2.3).\n";

    realValue = CorrectReading::nextDoublePositive(msg);

    cout << "Valor leído: " << realValue << endl << endl;


    cout << "********************************************" << endl;
    cout << "Test de lectura de enteros en el rango [1, 3]" << endl;
    cout << "(Actividad 4)" << endl;
    cout << "********************************************" << endl;

    msg = "\n--> Introduce varios valores inválidos "
          "(por ejemplo: hola, 3.5, -1, 5) y finalmente uno válido "
          "(por ejemplo: 1, +2, 3).\n";

    intValue = CorrectReading::nextInt(msg, 1, 3);

    cout << "Valor leído: " << intValue << endl << endl;

    return 0;
}