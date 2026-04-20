#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <time.h>
#include <chrono>
#include <string>
#include "measurableAlgorithms.h"
using namespace std;

#define MAXTALLA 10000
#define INITALLA 1000
#define INCRTALLA 1000
#define REPETICIONESQ 200
#define REPETICIONESL 20000
#define INITALLA_MERGE pow(2, 10)
#define MAXTALLA_MERGE pow(2, 19)

void createArray(int a[], int tamanyo) {
    for (int i = 0; i < tamanyo; i++) { a[i] = i; }
}

/*  Rellena los elementos de un array a de int
 *  con valores aleatorios entre 0 y tamanyo - 1.
 *
 *  a int[], el array.
 *  tamanyo int, el tamanyo del array a.
 */
void fillArrayRandom(int a[], int tamanyo) {
    for (int i=0; i<tamanyo; i++){
        a[i]=rand() % tamanyo;
    }
}

/*  Rellena los elementos de un array a de forma creciente,
 *  con valores desde 0 hasta tamanyo-1.
 *
 *  a int[], el array.
 *  tamanyo int, el tamanyo del array a.
 */
void fillArraySortedInAscendingOrder(int a[], int tamanyo) {
    for (int i=0; i<tamanyo; i++){
	    a[i]=i;
}
}
/*  Rellena los elementos de un array a de forma decreciente,
 *  con valores desde tamanyo-1 hasta 0.
 *
 *  a int[], el array.
 *  tamanyo int, el tamanyo del array a.
 */
void fillArraySortedInDescendingOrder(int a[], int tamanyo) {
       	for (int i=0; i<tamanyo; i++){
	    a[i]=tamanyo-1-i;
	}
}

void measuringSelectionSort() {
    long tt = 0; // Tiempos inicial, final y total
    // Imprimir cabecera
	cout << "# Seleccion. Tiempos en microsegundos\n";
	cout << "# Talla    Promedio \n";
	cout << "#------------------\n";
    
    for (int t = INITALLA; t <= MAXTALLA; t += INCRTALLA){
	int a[t];
	createArray (a,t);
	tt=0;
	for (int r=0; r<REPETICIONESQ; r++){
		int aux = rand() % t; //Generamos un número aleatorio para buscar
		fillArrayRandom(a,t);
		auto ti = chrono::high_resolution_clock::now(); //Guarda la hora del reloj inicial
		linearSearch(a, t, aux);
		auto tf = chrono::high_resolution_clock::now(); //Guarda la hora del reloj final
		tt += chrono::duration_cast<chrono::microseconds>(tf - ti).count(); //Calcula el tiempo transcurrido.
	}
	double tPromed = (double) tt / REPETICIONESQ; //Calcula el tiempo promedio de las 200 repeticiones

                // Imprimir resultados
    cout << std::setw(8) << t << std::setw(10) << std::fixed << std::setprecision(3) << tPromed
			 << std::endl;
    }	


}

void measuringInsertionSort() {
    long tt = 0; // Temps inicial, final i total
    // Imprimir cabecera de resultados
	cout << "# Insercion. Tiempos en microsegundos.\n";
	cout << "# Talla    Mejor       Peor     Promedio \n";
	cout << "#----------------------------------------\n";
    
    // COMPLETAR
}

void help() {
	cout << "Uso: ./MeasurigSortingAlgorithms num_algoritmo\n";
	cout << "   donde num_algoritmo es: \n";
	cout << "   1 -> Seleccion\n";
	cout << "   2 -> Insercion\n";
	cout << "   3 -> MergeSort\n";
}

int main(int argc, char *argv[]) {
	srand(time(0));  // Inicializar la semilla UNA sola vez aquí
    if (argc != 2) { help(); }
    else {
        int a =stoi(argv[1]) ;
        switch (a) {
            case 1:
                measuringSelectionSort();
                break;
            case 2:
                measuringInsertionSort();
                break;
            default:
                help();
        }
        
    }
    return 0;
}
