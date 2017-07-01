#include <cmath>
#include <iostream>
using namespace std;

int main() {
  while (true) {
    int D, E;
    cin >> D >> E;

    if (D == 0) {
      break;
    }
    
    double minerr = abs(D - E);
    for (int x = 0; x <= D / 2; x++) {
      int y = D - x;
      double err = abs(sqrt(x * x + y * y) - E);

      if (err < minerr) {
	minerr = err;
      }
    }

    cout << minerr << endl;
  }

  return 0;
}
