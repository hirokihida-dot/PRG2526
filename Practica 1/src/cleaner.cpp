/**
 * @file cleaner.cpp
 * @brief Ejercicio recursivo de limpieza (DFS flood-fill).
 *
 * Completar la lógica recursiva de clean().
 */

#include <iostream>
#include "cleaner.h"
using namespace std;

bool inRange(int r, int c) {
    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

void showGrid(char grid[ROWS][COLS]) {
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j)
            cout << grid[i][j];
        cout << '\n';
    }
    cout << '\n';
}

/**
 * @brief Limpia recursivamente las celdas alcanzables comenzando desde (r,c).
 */
int clean(int r, int c, char grid[ROWS][COLS]) {
	if (inRange (r, c) == false || grid[r][c] == '#'){	    	// TODO: CASOS BASE
  		return 0;
	}
	

	int counter = 0;
	
	
	if ( grid[r][c] == '.'){           //TODO: PROCESAR CELDA ACTUAL
			grid[r][c] = '*';
			counter = counter + 1;
		}
	else {
		return 0;
	}

	
	counter = counter + clean (r , c + 1, grid); //TODO: CASOS RECURSIVOS
	counter = counter + clean (r , c - 1, grid);
	counter = counter + clean (r + 1, c , grid);
	counter = counter + clean (r - 1, c , grid);
	
	return counter;
    
}
