#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  long N, K;
  cin >> N >> K;

  vector<long> v(N);
  for (long i = 0; i < N; i++) {
    long a, b;
    cin >> a >> b;

    v[i] = a * 1000000 + b;
  }

  sort(v.begin(), v.end());
  long k = 0;
  long ans = 0;
  for (long i = 0; i < N; i++) {
    k += v[i] % 1000000;
    ans = v[i] / 1000000;

    if (k >= K) {
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
