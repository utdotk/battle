#include <cmath>
#include <iostream>
using namespace std;

long mod(long x) {
  return x % 1000000007;
}

long fact(long x) {
  if (x == 0) {
    return 1;
  }
  return mod(x * fact(x - 1));
}

int main(void) {
  long N, M;
  cin >> N >> M;
  long c = N == M ? 2 : abs(N - M) == 1 ? 1 : 0;
  cout << mod(c * mod(fact(N) * fact(M))) << endl;
  return 0;
}
