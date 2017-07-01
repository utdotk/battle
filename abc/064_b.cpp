#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int max = 0;
  int min = 1000;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    if (a > max) {
      max = a;
    }
    if (a < min) {
      min = a;
    }
  }

  cout << max - min << endl;

  return 0;
}
