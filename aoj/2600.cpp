#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

struct Xfi {
  bool operator<(const Xfi &xfi) const {
    return x - w < xfi.x - xfi.w;
  }
  int x, w;
};

struct Yfi {
  bool operator<(const Yfi &yfi) const {
    return y - w < yfi.y - yfi.w;
  }
  int y, w;
};

int main() {
  int N, W, H;
  cin >> N >> W >> H;

  vector<Xfi> xfis(N);
  vector<Yfi> yfis(N);

  for (int i = 0; i < N; i++) {
    int x, y, w;
    cin >> x >> y >> w;

    xfis[i].x = x;
    yfis[i].y = y;
    xfis[i].w = yfis[i].w = w;
  }

  bool flg = false;

  sort(xfis.begin(), xfis.end());
  int x = 0;
  for (int i = 0; i < N; i++) {
    if (xfis[i].x - xfis[i].w > x) {
      flg = true;
      break;
    }
    x = max(xfis[i].x + xfis[i].w, x);
  }
  flg = x < W || flg;

  if (flg) {
    flg = false;
    sort(yfis.begin(), yfis.end());
    int y = 0;
    for (int i = 0; i < N; i++) {
      if (yfis[i].y - yfis[i].w > y) {
        flg = true;
        break;
      }
      y = max(yfis[i].y + yfis[i].w, y);
    }
    flg = y < H || flg;
  }

  cout << (!flg ? "Yes" : "No") << endl;

  return 0;
}
