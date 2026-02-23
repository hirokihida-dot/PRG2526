#ifndef CLEANER_H
#define CLEANER_H

/**
 * @file cleaner.h
 * @brief Limpieza recursiva de celdas alcanzables y conteo de celdas limpiadas.
 *
 * Representación del mapa:
 * - '#' : pared/obstáculo
 * - '.' : suelo sucio (limpiable)
 * - '*' : celda limpiada/visitada
 */
constexpr int ROWS = 6;
constexpr int COLS = 10;

/**
 * @brief Comprueba si (r,c) está dentro de los límites del mapa.
 */
bool inRange(int r, int c);

/**
 * @brief Muestra el mapa.
 */
void showGrid(char grid[ROWS][COLS]);

/**
 * @brief Limpia todas las celdas alcanzables desde (r,c).
 *
 * No se usa matriz de visitados. La función marca las celdas visitadas como '*'.
 *
 * @param r Fila inicial
 * @param c Columna inicial
 * @param grid Matriz del mapa 
 * @return Número de celdas limpiadas/alcanzadas
 */
int clean(int r, int c, char grid[ROWS][COLS]);

#endif
