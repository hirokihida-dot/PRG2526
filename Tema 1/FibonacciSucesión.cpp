#include <iostream>
using namespace std;

int fibonacci (int n) {
  if (n == 1 || n == 0)
    return n;                                    //caso base
  else 
    return fibonacci (n-1) + fibonacci (n-2);  //caso recursivo
}

int main {
  cout << "Introduce el número de la sucesión de fibonacci que quieres calcular " << endl;
  int termino = 0;
  cin >> termino;
  cout << "El termino " << termino << " de la sucesión es: " << fibonacci (termino);
  return 0;    
}
