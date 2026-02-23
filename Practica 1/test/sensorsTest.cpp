/**
 * @file sensors_test.cpp
 * @brief Tests manuales completos para las funciones recursivas de sensores (con índice ini).
 *
 * Suposiciones:
 * - n > 0 (siempre hay al menos un sensor)
 * - Firmas de las funciones:
 *      int minDist(const int a[], int ini, int n);
 *      bool allSafe(const int a[], int ini, int n, int threshold);
 *      int countDangerous(const int a[], int ini, int n, int threshold);
 */
#include <iostream>
#include "sensors.h"
using namespace std;

int main() {

    cout << "===== TESTS DE SENSORES =====\n\n";

    // --------------------------------------------------
    // Test 1: Valores mezclados
    // --------------------------------------------------
    {
        int a[] = {50, 20, 80, 10};
        int n = 4;
        int thr = 30;

        cout << "Test 1: Valores mezclados\n";
        cout << "minDist -> esperado 10, obtenido " << minDist(a, 0, n) << "\n";
        cout << "allSafe -> esperado false, obtenido "
             << (allSafe(a, 0, n, thr) ? "true" : "false") << "\n";
        cout << "countDangerous -> esperado 2, obtenido "
             << countDangerous(a, 0, n, thr) << "\n\n";
    }

    // --------------------------------------------------
    // Test 2: Todos seguros
    // --------------------------------------------------
    {
        int a[] = {40, 35, 100};
        int n = 3;
        int thr = 30;

        cout << "Test 2: Todos seguros\n";
        cout << "minDist -> esperado 35, obtenido " << minDist(a, 0, n) << "\n";
        cout << "allSafe -> esperado true, obtenido "
             << (allSafe(a, 0, n, thr) ? "true" : "false") << "\n";
        cout << "countDangerous -> esperado 0, obtenido "
             << countDangerous(a, 0, n, thr) << "\n\n";
    }

    // --------------------------------------------------
    // Test 3: Todos peligrosos
    // --------------------------------------------------
    {
        int a[] = {5, 7, 12};
        int n = 3;
        int thr = 30;

        cout << "Test 3: Todos peligrosos\n";
        cout << "minDist -> esperado 5, obtenido " << minDist(a, 0, n) << "\n";
        cout << "allSafe -> esperado false, obtenido "
             << (allSafe(a, 0, n, thr) ? "true" : "false") << "\n";
        cout << "countDangerous -> esperado 3, obtenido "
             << countDangerous(a, 0, n, thr) << "\n\n";
    }

    // --------------------------------------------------
    // Test 4: Un único elemento
    // --------------------------------------------------
    {
        int a[] = {25};
        int n = 1;
        int thr = 30;

        cout << "Test 4: Un único elemento\n";
        cout << "minDist -> esperado 25, obtenido " << minDist(a, 0, n) << "\n";
        cout << "allSafe -> esperado false, obtenido "
             << (allSafe(a, 0, n, thr) ? "true" : "false") << "\n";
        cout << "countDangerous -> esperado 1, obtenido "
             << countDangerous(a, 0, n, thr) << "\n\n";
    }

    // --------------------------------------------------
    // Test 5: Valores iguales al umbral
    // --------------------------------------------------
    {
        int a[] = {30, 30, 30};
        int n = 3;
        int thr = 30;

        cout << "Test 5: Valores iguales al umbral\n";
        cout << "minDist -> esperado 30, obtenido " << minDist(a, 0, n) << "\n";
        cout << "allSafe -> esperado true, obtenido "
             << (allSafe(a, 0, n, thr) ? "true" : "false") << "\n";
        cout << "countDangerous -> esperado 0, obtenido "
             << countDangerous(a, 0, n, thr) << "\n\n";
    }

    cout << "===== FIN TESTS DE SENSORES =====\n";
    return 0;
}
