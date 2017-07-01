#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;

  bool flg = false;
  for (int i = 0; i < 100000; i++) {
    if ((B * i + C) % A == 0) {
      flg = true;
      break;
    }
  }

  cout << (flg ? "YES" : "NO") << endl;

  return 0;
}
