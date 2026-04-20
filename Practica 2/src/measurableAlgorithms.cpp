#include <iostream>
using namespace std;

/*  Linear Search
 *
 *  a int[], array of int
 *  tamanyo int, the size of the array a
 *  e int, value to look for
 *  Devuelve int, position of e in a or -1 if e is not in a
 */
int linearSearch(int a[], int tamanyo, int e) {
    int i = 0;
    while (i < tamanyo && (a[i] != e)) { i++; }
    if (i < tamanyo) { return i; }
    else { return -1; }
}

/*  Selection Sort
 *
 *  a int[], array of int
 *  tamanyo int, the size of the array a
 */
void selectionSort(int a[], int tamanyo) {
    int posMin, temp;
    for (int i = 0; i < tamanyo - 1; i++) {
        posMin = i;
        for (int j = i + 1; j < tamanyo; j++) {
            if (a[j] < a[posMin]) { posMin = j; }
        }
        temp = a[posMin];
        a[posMin] = a[i];
        a[i] = temp;
    }
}

/*  InsertionSort
 *  a int[], array of int
 *  tamanyo int, the size of the array a
 */
void insertionSort(int a[], int tamanyo) {
    int temp;
    for (int i = 1; i < tamanyo; i++) {
        int j = i - 1;
        temp = a[i];
        while (j >= 0 && a[j] > temp) {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

/*  Natural Merge to be used in Merge Sort
 *
 *  a int[], array of int
 *  left  int, leftmost position of the slice
 *  of the array to to be sorted
 *  right int, rightmost position of the slice
 *  of the array to to be sorted
 *  half  int, central position of the slice
 *  of the array to to be sorted
 */
void naturalMerge(int a[], int left, int half, int right) {
    int temp[right - left + 1];
    int i = left, j = half + 1, k = 0;
    while (i <= half && j <= right) {
        if (a[i] < a[j]) { temp[k++] = a[i++]; }
        else { temp[k++] = a[j++]; }
    }
    
    while (i <= half) { temp[k++] = a[i++]; }
    while (j <= right) { temp[k++] = a[j++]; }
    
    for (i = left, k = 0; i <= right; i++) {
        a[i] = temp[k++];
    }
}

/*  mergeSort
 *
 *  a int[], array of int
 *  left  int, leftmost position of the slice
 *  of the array to to be sorted
 *  right int, rightmost position of the slice
 *  of the array to to be sorted
 */
void mergeSort(int a[], int left, int right) {
    int half;
    if (left < right) {
        half = (left + right) / 2;
        mergeSort(a, left, half);
        mergeSort(a, half + 1, right);
        naturalMerge(a, left, half, right);
    }
}




