#include <iostream>
using namespace std;

int main() {
  long N, A, B;
  cin >> N >> A >> B;

  if (A > B || (N == 1 && A != B)) {
    cout << 0 << endl;
    return 0;
  }

  cout << B * (N - 2) - A * (N - 2) + 1 << endl;

  return 0;
}
