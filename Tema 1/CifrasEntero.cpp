#include <iostream>
using namespace std;

int NumCifras(int n){
  if (n < 10)
    return 1;
  else
    return NumCifras (int n/10)+1;
}

//terminar
