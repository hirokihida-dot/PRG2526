/**
 * @file sensors.cpp
 * @brief Procesamiento recursivo de lecturas de sensores usando un índice.
 *
 * Suposición: n > 0 (siempre hay al menos un sensor).
 *
 * Completar minDist, allSafe y countDangerous.
 */
#include "sensors.h"

/**
 * @brief Calcula recursivamente el valor mínimo entre n > 0 lecturas.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @return Valor mínimo en a[ini..n-1].
 */
int minDist(const int a[], int ini, int n) {
	if (ini == n-1){ 			//TODO: CASO BASE
		return a[ini];
	}

	else{                                        //TODO: PASO RECURSIVO
		int min = minDist( a, ini + 1, n);
		if (min <= a[ini]){
   			return min;
		}

		else{
			return a[ini];	
		}	
	}   	
}

/**
 * @brief Comprueba recursivamente si todas las lecturas son >= threshold.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @param threshold Umbral de seguridad.
 * @return true si todas las lecturas a[ini..n-1] son >= threshold; false en caso contrario.
 */
bool allSafe(const int a[], int ini, int n, int threshold) {
	if (ini == n-1){       // TODO: CASO BASE
		if (a[ini] > threshold){
	    		return true;
		}

		else{
			return false;
		}
	}

	else{   // TODO: CASO RECURSIVO
		if (a[ini] > threshold){
			return allSafe( a, ini+1, n, threshold);
		}

		else{
			return false;
		}
 	}
}

/**
 * @brief Cuenta recursivamente cuántas lecturas son menores que el umbral.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @param threshold Umbral de seguridad.
 * @return Número de lecturas en a[ini..n-1] que son < threshold.
 */
int countDangerous(const int a[], int ini, int n, int threshold) {
	
	if (ini == n-1){		 // TODO: CASO BASE
   		if (a[ini] < threshold){
			return 1;
		}
		else{
			return 0;
		}
	}

	else{         //TODO: PASO RECURSIVO
		if (a[ini] < threshold){
			return  countDangerous (a, ini + 1, n, threshold) + 1;
		}

		else{
			return  countDangerous (a, ini + 1, n, threshold);
		}
	}
	
   
}
