#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = 1;
  int sgn = 0;
  int lA;
  cin >> lA;
  for (int i = 1; i < N; i++) {
    int A;
    cin >> A;

    if (sgn == 0) {
      sgn = A > lA ? 1 : A < lA ? -1 : 0;
    }

    if (sgn == 1 && A < lA || sgn == -1 && A > lA) {
      sgn = 0;
      cnt++;
    }
    lA = A;
  }

  cout << cnt << endl;
  return 0;
}
