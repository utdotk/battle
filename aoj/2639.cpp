#include <iostream>
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;

  int T = -1;
  for (int t = 0; t < 60; t++) {
    if ((60 * t + c) % (a + b) <= a) {
      T = 60 * t + c;
      break;
    }
  }

  cout << T << endl;

  return 0;
}
