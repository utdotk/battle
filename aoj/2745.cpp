#include <iostream>
using namespace std;

int main() {
  while (true) {
    int R0, W0, C, R;
    cin >> R0 >> W0 >> C >> R;

    if (R0 == 0) {
      break;
    }
    
    int x = 0;
    for (; (double)(x * R + R0) / C - W0 < 0.0; x++) {
    }

    cout << x << endl;
  }

  return 0;
}
