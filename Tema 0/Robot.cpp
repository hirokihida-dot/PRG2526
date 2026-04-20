#include <iostream>
using namespace std;
  class Robot {
    public:
    float velocidad;
    void configurarVelocidad(float v) {
      velocidad = v;
    }
    void mostrarEstado() {
      cout << "Velocidad del robot: " << velocidad << " m/s" << endl;
    }
  };

  int main() {
    Robot r;
    float v;
    cout << "Introduce la velocidad del robot (m/s): ";
    cin >> v;
    r.configurarVelocidad(v);
    r.mostrarEstado();
    return 0;
  }
