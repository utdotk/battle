#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  int e;
  while (cin >> e, e != 0) {
    int m = 1000000;
    for (int z = 0; z * z * z <= e; z++) {
      int y = (int)sqrt(e - z * z * z);
      m = min(m, (e - z * z * z - y * y) + y + z);
    }

    cout << m << endl;
  }

  return 0;
}
