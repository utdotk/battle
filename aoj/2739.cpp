#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M, T;
  cin >> N >> M >> T;

  vector<int> a(N + 1);
  a[0] = 0;
  for (int i = 1; i <= N; i++) {
    cin >> a[i];
  }

  int ans = T;
  int t1 = a[N];
  int t2 = a[N];
  for (int i = N - 1; i >= 0; i--) {
    if (t2 - a[i] < M * 2 && a[i] != 0) {
      t2 = a[i];
    } else {
      int tmp = ans;
      ans -= (t1 - t2) + M;
      ans -= T - t1 < M ? T - t1 : M;
      t1 = t2 = a[i];
    }
  }

  cout << ans << endl;

  return 0;
}
