#include <iostream>
#include <vector>
using namespace std;

vector<vector<int> > B;

int revNum(int num) {
  return 7 - num;
}

int isHeavy(int num) {
  return num > 3;
}

int heavyNum(int num) {
  return isHeavy(num) ? num : revNum(num);
}

int sideHeavyNum(int t, int f) {
  return 15 - heavyNum(t) - heavyNum(f);
}

int check(int t, int f) {
  int ht = heavyNum(t);
  int hf = heavyNum(f);
  return (ht - hf + 2) % 3;
}

int leftNum(int t, int f) {
  int s = sideHeavyNum(t, f);
  return (isHeavy(t) + isHeavy(f) + check(t, f)) % 2 ? revNum(s) : s;
}

int canDrop(int x, int y, int h) {
  return B[x][y] >> 3 < h;
}

void dropDice(int t, int f, int x, int y) {
  int l = leftNum(t, f);
  int h = B[x][y] >> 3;

  int xx = x - (isHeavy(l) ? 1 : -1);
  int xy = y;
  int yx = x;
  int yy = y - (isHeavy(f) ? 1 : -1);

  if (!canDrop(xx, xy, h) && !canDrop(yx, yy, h)) {
    B[x][y] &= ~7;
    B[x][y] |= t;
    B[x][y] += 8;
    return;
  }

  int hf = heavyNum(f);
  int hl = heavyNum(l);

  if (hl > hf) {
    if (canDrop(xx, xy, h)) {
      dropDice(revNum(hl), f, xx, xy);
    } else {
      dropDice(revNum(hf), isHeavy(f) ? t : revNum(t), yx, yy);
    }
  } else {
    if (canDrop(yx, yy, h)) {
      dropDice(revNum(hf), isHeavy(f) ? t : revNum(t), yx, yy);
    } else {
      dropDice(revNum(hl), f, xx, xy);
    }
  }
}

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    int l = 2 * n + 1;
    B.resize(l);
    for (int i = 0; i < l; i++) {
      B[i].resize(l);
      fill(B[i].begin(), B[i].end(), 0);
    }

    for (int i = 0; i < n; i++) {
      int t, f;
      cin >> t >> f;

      dropDice(t, f, n, n);
    }

    vector<int> cnt(7);
    fill(cnt.begin(), cnt.end(), 0);
    for (int i = 0; i < l; i++) {
      for (int j = 0; j < l; j++) {
	cnt[B[i][j] & 7]++;
      }
    }

    for (int i = 1; i < 7; i++) {
      cout << cnt[i];
      if (i != 6) {
	cout << ' ';
      }
    }
    cout << endl;
  }

  return 0;
}
