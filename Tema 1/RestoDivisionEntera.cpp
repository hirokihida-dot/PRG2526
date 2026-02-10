#include <iostream>
using namespace std;

int restoDivisionEntera(int a, int b) {
  if(a < b) {       //caso base
    return a;
  } else {         //caso recursivo
    return restoDivisionEntera(a - b, b);
  }
}

int main() {
  cout << "resultado 6/2: " << restoDivisionEntera(6, 2) << endl;
  cout << "resultado 2/6: " << restoDivisionEntera(2, 6) << endl;
  return 0;
}
