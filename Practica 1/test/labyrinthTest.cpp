#include <iostream>
#include "labyrinth.h"

using namespace std;

void runTest(const char* name, char labyrinth[ROWS][COLS]) {
    bool visited[ROWS][COLS] = {};
    int rr = -1, rc = -1;

    // Localizar 'R'
    for (int i = 0; i < ROWS; ++i)
        for (int j = 0; j < COLS; ++j)
            if (labyrinth[i][j] == 'R') { rr = i; rc = j; }

    cout << "=============================\n";
    cout << name << "\n";
    cout << "=============================\n";

    if (rr == -1) {
        cout << "ERROR: No se encuentra 'R'\n\n";
        return;
    }

    cout << "Laberinto inicial:\n";
    showLabyrinth(labyrinth);

    bool ok = findExit(labyrinth, visited, rr, rc);

    cout << "Resultado: " << (ok ? "Existe camino a 'E'" : "No hay camino a 'E'") << "\n";
    // Restaurar 'R' por claridad (no debería pisarse)
    labyrinth[rr][rc] = 'R';
    cout << "Laberinto tras la búsqueda (camino '*' si existe):\n";
    showLabyrinth(labyrinth);
}

int main() {
    // 1) Camino existente sencillo
    char lab1[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#'},
        {'#','R','.','.','.','#','.','.','#'},
        {'#','#','#','#','.','#','#','.','#'},
        {'#','.','.','#','.','.','.','.','#'},
        {'#','.','#','#','#','#','#','E','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    // 2) Salida bloqueada por paredes
    char lab2[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#'},
        {'#','R','.','#','.','#','.','.','#'},
        {'#','#','.','#','.','#','#','.','#'},
        {'#','.','.','#','.','#','.','.','#'},
        {'#','.','#','#','#','#','#','E','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    // 3) Robot en el borde superior izquierdo
    char lab3[ROWS][COLS] = {
        {'R','.','.','#','#','#','#','#','#'},
        {'.','#','.','.','.','.','#','.','#'},
        {'.','#','#','#','#','.','#','.','#'},
        {'.','.','.','.','#','.','.','.','#'},
        {'#','#','#','.','#','#','#','E','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    // 4) Callejón sin salida cerca de R
    char lab4[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#'},
        {'#','R','.','#','#','#','#','#','#'},
        {'#','#','.','#','#','#','#','#','#'},
        {'#','#','.','.','.','.','.','E','#'},
        {'#','#','#','#','#','#','#','#','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    // 5) Múltiples desvíos; uno conduce a 'E'
    char lab5[ROWS][COLS] = {
        {'#','#','#','#','#','#','#','#','#'},
        {'#','R','.','.','#','.','.','.','#'},
        {'#','#','#','.','#','.','#','.','#'},
        {'#','.','.','.','.','.','#','.','#'},
        {'#','.','#','#','#','.','.','E','#'},
        {'#','#','#','#','#','#','#','#','#'}
    };

    runTest("Test 1: Camino existente", lab1);
    runTest("Test 2: Salida bloqueada", lab2);
    runTest("Test 3: R en borde", lab3);
    runTest("Test 4: Callejón sin salida cerca de R", lab4);
    runTest("Test 5: Varios desvíos, uno válido", lab5);

    return 0;
}
