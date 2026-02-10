#include <iostream>
using namespace std;

int potencia (int a, int n){
  if (n==0)      //caso base
    return 1;
  else          // caso recursivo
    return potencia (a, n-1) * a; 
}

int main{
  int res = potencia (2, 3);
}
