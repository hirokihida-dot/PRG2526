/*
 *  * @file labyrinth.cpp
 *   * @brief Laberintos con DFS recursivo + backtracking.
 *    *
 *     * Completar la lógica recursiva en findExit().
 *      */

#include <iostream>
#include "labyrinth.h"
using namespace std;

/**
 *  * @brief Comprueba si (r,c) está dentro de los límites del laberinto.
 *   */
bool inRange(int r, int c) {
	    return (r >= 0 && r < ROWS && c >= 0 && c < COLS);
}

/**
 *  * @brief Imprime el laberinto.
 *   */
void showLabyrinth(char labyrinth[ROWS][COLS]) {
	    for (int i = 0; i < ROWS; ++i) {
		            for (int j = 0; j < COLS; ++j)
				                cout << labyrinth[i][j];
			            cout << '\n';
				        }
	        cout << '\n';
}

/**
 *  * @brief Busca recursivamente la salida 'E' comenzando en (r,c).
 *   */
bool findExit(char labyrinth[ROWS][COLS], bool visited[ROWS][COLS], int r, int c) {
	if (inRange (r, c) == false || labyrinth [r][c] == '#'){	    // TODO: CASOS BASE
		return false;
	}
	else{
		if (visited[r][c] == true){
			return false;
		}
		else if (labyrinth[r][c] == 'E'){
			return true;
		}
	}
	visited[r][c] = true;  //TODO: MARCAR CASILLA COMO VISITADA	
    	bool caminoCorrecto = false;
	caminoCorrecto = findExit (labyrinth, visited, r, c-1);	// TODO: EXPLORACIÓN RECURSIVA
	if (caminoCorrecto == false){
		caminoCorrecto = findExit (labyrinth, visited, r, c+1);
	}
	if (caminoCorrecto == false){
		caminoCorrecto = findExit (labyrinth, visited, r-1, c);
		
	}
	if (caminoCorrecto == false){
		caminoCorrecto = findExit (labyrinth, visited, r+1, c);
	}
	
	if (caminoCorrecto == true){
		labyrinth[r][c] = '*';
		return true;
	}

	else{
		return false;
	}
}
