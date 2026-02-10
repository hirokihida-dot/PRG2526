#include <iostream>
using namespace std;
int cuentaAtras(int n);
int main() {
  int r = cuentaAtras(30);
  return 0;
}

int cuentaAtras(int n) {
  std::cout << "n = " << n << std::endl;
  if (n == 0) {               // Parece correcto…
    return 0;
  } else {
    return cuentaAtras(n + 1); // No se reduce el problema, ejemplo de Overflow en la pila, se arregla poniendo cuentaAtras(n-1)
  }
}
