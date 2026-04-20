#include <iostream>
#include <string>
#include <chrono>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include "measurableAlgorithms.h"
using namespace std;

// Constantes que definen los parametros de medida
#define MAXTALLA 100000
#define INITALLA 10000
#define INCRTALLA 10000
#define REPETICIONES 100000
#define REP_CASOMEJOR 2000000


/*  Crea un array de int de talla tamanyo,
 *  con valores crecientes desde 0 hasta tamanyo-1.
 *
 *  int[], el array.
 *  int, el tamanyo del array
 */
void createArray(int a[], int tamanyo) {
    for (int i = 0; i < tamanyo; i++) { a[i] = i; }
}

void measuringLinearSearch() {
    
    long long tt = 0; // Tiempos inicial, final y total
    // Imprimir cabecera de resultados
    cout << "# Busqueda lineal. Tiempos en microsegundos\n";
    cout << "# Talla       Mejor       Peor     Promedio\n";
    cout << "#------------------------------------------\n";
    
    // Este bucle repite el proceso para varias tallas
    for (int t = INITALLA; t <= MAXTALLA; t += INCRTALLA) {
        // Crear el array una vez para cada talla
        int a[t];
        createArray(a, t);
        // Estudio del Caso mejor: buscar a[0]
        // OJO: Como es muy rapido,
        // el numero de repeticiones es mayor
        tt = 0;                        // Tiempo acumulado inicial a 0
        for (int r = 0; r < REP_CASOMEJOR; r++) {
            // Tiempo inicial
            auto ti = chrono::high_resolution_clock::now();
            linearSearch(a, t, a[0]);
            // Tiempo final
            auto tf = chrono::high_resolution_clock::now();
            tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
            //count da el resultado en milisegundos
            // Actualizar tiempo acumulado
        }
        
        double tMejor = (double) tt / REP_CASOMEJOR; // Tiempo promedio
        // del caso mejor
        
        // Estudio del Caso peor: buscar uno que no esta, por ejemplo -1
        tt = 0;                        // Tiempo acumulado inicial a 0
        for (int r = 0; r < REPETICIONES; r++) {
            auto ti = chrono::high_resolution_clock::now();
            linearSearch(a, t, -1);
            auto tf = chrono::high_resolution_clock::now();
            tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
        }
  
        double tPeor = (double) tt / REPETICIONES; // Tiempo promedio
        // del caso peor
        
        // Estudio del Caso promedio: buscar un numero
        // aleatorio entre 0 y t-1
        tt = 0;                        // Tiempo acumulado inicial a 0
        for (int r = 0; r < REPETICIONES; r++) {
            int aux = rand() % t; // Num a buscar
            //cout << "numero a buscar "<< aux << endl;
            auto ti = chrono::high_resolution_clock::now();
            linearSearch(a, t, aux);
            auto tf = chrono::high_resolution_clock::now();
            tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count();
        }

        double tPromed = (double) tt / REPETICIONES; // Tiempo promedio
        // del caso promedio
        
        // Imprimir resultados
	    cout << std::setw(8) << t << std::setw(10) << std::fixed << std::setprecision(3) << tMejor << std::setw(10) << std::fixed << std::setprecision(3) << tPeor << std::setw(10) << std::fixed << std::setprecision(3) << tPromed
			 << std::endl;
    }
}

int main() {
    srand(time(0));
    measuringLinearSearch();
    return 0;
}


