#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

long max4(long a, long b, long c, long d) {
  return max(max(a, b), max(c, d));
}

long min4(long a, long b, long c, long d) {
  return min(min(a, b), min(c, d));
}

long opmax(long a, long b) {
  if (b == 0) {
    return max(max(a + b, a - b), a * b);
  }
  return max4(a + b, a - b, a * b, a / b);
}

long opmin(long a, long b) {
  if (b == 0) {
    return min(min(a + b, a - b), a * b);
  }
  return min4(a + b, a - b, a * b, a / b);
}

int main() {
  long N;
  cin >> N;

  vector<long> a(N);
  for (long i = 0; i < N; i++) {
    cin >> a[i];
  }

  vector<vector<long> > DP(N);
  for (long i = 0; i < N; i++) {
    DP[i].resize(2);
    DP[i][0] = DP[i][1] = 0;
  }

  DP[0][0] = DP[0][1] = a[0];
  for (long i = 1; i < N; i++) {
    DP[i][0] = max(opmax(DP[i - 1][0], a[i]),
		   opmax(DP[i - 1][1], a[i]));
    DP[i][1] = min(opmin(DP[i - 1][0], a[i]),
		   opmin(DP[i - 1][1], a[i]));
  }

  cout << DP[N - 1][0] << endl;

  return 0;
}
