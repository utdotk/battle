#include <iostream>
#include <vector>
using namespace std;

vector<int> x;
vector<int> y;

long mod(long l) {
  return l % 1000000007;
}

long b(int i) {
  if (i == 0 || y[i - 1] == 0) {
    return 1;
  }
  return mod(mod(y[i - 1]) * b(i - 1) + 1);
}

long a(int i) {
  if (i == 0) {
    return 1;
  }
  if (x[i - 1] == 0) {
    return a(i - 1);
  }
  long bb = mod(b(i - 1));
  return mod(mod(x[i - 1]) * mod(bb * bb) + a(i - 1));
}

int main() {
  int n, q;
  cin >> n >> q;
  x.resize(n);
  fill(x.begin(), x.end(), 0);
  y.resize(n);
  fill(y.begin(), y.end(), 0);

  for (int i = 0; i < q; i++) {
    char c;
    int j;
    cin >> c >> j;
    if (c == 'x') {
      cin >> x[j];
    } else if (c == 'y') {
      cin >> y[j];
    } else {
      cout << a(j) << endl;
    }
  }

  return 0;
}
