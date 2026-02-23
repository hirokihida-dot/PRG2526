/**
 * @file sensors.h
 * @brief Declaraciones para el procesamiento recursivo de lecturas de sensores usando un parámetro índice.
 *
 * Suposición: n > 0 (siempre hay al menos un sensor).
 */
#ifndef SENSORS_H
#define SENSORS_H

/**
 * @brief Calcula recursivamente el valor mínimo entre n > 0 lecturas.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @return Valor mínimo en a[ini..n-1].
 */
int minDist(const int a[], int ini, int n);

/**
 * @brief Comprueba de forma recursiva si todas las lecturas son >= threshold.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @param threshold Umbral de seguridad.
 * @return true si todas las lecturas a[ini..n-1] son >= threshold; false en caso contrario.
 */
bool allSafe(const int a[], int ini, int n, int threshold);

/**
 * @brief Cuenta recursivamente cuántas lecturas están por debajo del umbral.
 *
 * @param a Array de lecturas.
 * @param ini Índice actual (comenzando en 0).
 * @param n Número total de lecturas (n > 0).
 * @param threshold Umbral de seguridad.
 * @return Número de lecturas en a[ini..n-1] que son < threshold.
 */
int countDangerous(const int a[], int ini, int n, int threshold);

#endif // SENSORS_H
