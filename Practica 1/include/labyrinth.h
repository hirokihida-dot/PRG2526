#ifndef LABYRINTH_H
#define LABYRINTH_H

/**
 * @file labyrinth.h
 * @brief Búsqueda recursiva de salida en un laberinto y marcado del camino.
 *
 * Representación:
 * - '#' : pared
 * - '.' : celda libre
 * - 'R' : posición inicial (robot)
 * - 'E' : salida
 * - '*' : camino de éxito marcado durante el retorno
 */
constexpr int ROWS = 6;
constexpr int COLS = 9;

/**
 * @brief Comprueba si (r,c) está dentro de los límites del laberinto.
 * @param r Fila
 * @param c Columna
 * @return true si está dentro; false en caso contrario
 */
bool inRange(int r, int c);

/**
 * @brief Muestra el laberinto por la salida estándar.
 * @param labyrinth Matriz del laberinto
 */
void showLabyrinth(char labyrinth[ROWS][COLS]);

/**
 * @brief Busca recursivamente la salida 'E' desde (r,c).
 *
 * Evita ciclos usando la matriz visited. Si existe un camino desde (r,c) a 'E',
 * marca con '*' las celdas del camino de éxito durante el retorno (sin pisar
 * símbolos especiales como 'R' o 'E').
 *
 * @param labyrinth Laberinto
 * @param visited Matriz de visitados
 * @param r Fila actual
 * @param c Columna actual
 * @return true si hay camino a 'E'; false en caso contrario
 */
bool findExit(char labyrinth[ROWS][COLS], bool visited[ROWS][COLS], int r, int c);

#endif
