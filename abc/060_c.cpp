#include <iostream>
using namespace std;

int main() {
  int N, T;
  cin >> N >> T;

  int wt = 0;
  int lt = -T;
  for (int i = 0; i < N; i++) {
    int t;
    cin >> t;
    if (t - lt < T) {
      wt -= T - (t - lt);
    }
    wt += T;
    lt = t;
  }

  cout << wt << endl;

  return 0;
}
