#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
  long H, W;
  cin >> H >> W;

  if (H % 3 == 0 || W % 3 == 0) {
    cout << 0 << endl;
    return 0;
  }

  long mind = H;
  mind = min(mind, W);

  long h1 = H / 2;
  long h2 = H - h1;
  for (long i = 1; i <= W; i++) {
    long mx = max(i * H, max((W - i) * h1, (W - i) * h2));
    long mn = min(i * H, min((W - i) * h1, (W - i) * h2));
    if (mx - mn < mind) {
      mind = mx - mn;
    }
  }

  long w1 = W / 2;
  long w2 = W - w1;
  for (long i = 1; i <= H; i++) {
    long mx = max(i * W, max((H - i) * w1, (H - i) * w2));
    long mn = min(i * W, min((H - i) * w1, (H - i) * w2));
    if (mx - mn < mind) {
      mind = mx - mn;
    }
  }

  cout << mind << endl;

  return 0;
}
