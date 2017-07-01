#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  Node(int lx, int ly, int rx, int ry) {
    this->lx = lx;
    this->ly = ly;
    this->rx = rx;
    this->ry = ry;
  }

  int lx;
  int ly;
  int rx;
  int ry;
};

bool shining(const Node &n, bool s[50][50][50][50], int W) {
  int lX = n.lx - 1;
  int lY = n.ly - 1;
  int rX = n.rx - W - 2;
  int rY = n.ry - 1;

  bool ret = s[lX][lY][rX][rY];
  s[lX][lY][rX][rY] = true;

  return ret;
}

int main() {
  vector<vector<char> > f(103);
  for (int i = 0; i < f.size(); i++) {
    f[i].resize(52);
  }

  while (true) {
    int W, H;
    cin >> W >> H;

    if (W == 0) {
      break;
    }

    int cw = W + 1;
    int w = W * 2 + 3;
    int h = H + 2;
    for (int i = 0; i < w; i++) {
      f[i][0] = f[i][h - 1] = '#';
    }
    for (int i = 0; i < h; i++) {
      f[0][i] = f[cw][i] = f[w - 1][i] = '#';
    }

    int lx = 0, ly = 0;
    int rx = 0, ry = 0;
    for (int i = 1; i < h - 1; i++) {
      for (int j = 1; j < cw; j++) {
	cin >> f[j][i];
	if (f[j][i] == 'L') {
	  lx = j;
	  ly = i;
	  f[j][i] = '.';
	}
      }
      for (int j = cw + 1; j < w - 1; j++) {
	cin >> f[j][i];
	if (f[j][i] == 'R') {
	  rx = j;
	  ry = i;
	  f[j][i] = '.';
	}
      }
    }

    bool s[50][50][50][50];
    for (int i = 0; i < W; i++) {
      for (int j = 0; j < H; j++) {
	for (int k = 0; k < W; k++) {
	  for (int l = 0; l < H; l++) {
	    s[i][j][k][l] = false;
	  }
	}
      }
    }

    queue<Node> q;
    q.push(Node(lx, ly, rx, ry));
    shining(q.front(), s, W);
    while (!q.empty()) {
      Node n = q.front();

      if (f[n.lx][n.ly] == '%' && f[n.rx][n.ry] == '%') {
	cout << "Yes" << endl;
	break;
      }
      q.pop();

      if (f[n.lx][n.ly] == '%' || f[n.rx][n.ry] == '%') {
	continue;
      }

      Node nn(n.lx, f[n.lx][n.ly - 1] != '#' ? n.ly - 1 : n.ly,
	      n.rx, f[n.rx][n.ry - 1] != '#' ? n.ry - 1 : n.ry);

      if (!shining(nn, s, W)) {
	q.push(nn);
      }

      Node we(f[n.lx - 1][n.ly] != '#' ? n.lx - 1 : n.lx, n.ly,
	      f[n.rx + 1][n.ry] != '#' ? n.rx + 1 : n.rx, n.ry);

      if (!shining(we, s, W)) {
	q.push(we);
      }

      Node ew(f[n.lx + 1][n.ly] != '#' ? n.lx + 1 : n.lx, n.ly,
	      f[n.rx - 1][n.ry] != '#' ? n.rx - 1 : n.rx, n.ry);

      if (!shining(ew, s, W)) {
	q.push(ew);
      }

      Node ss(n.lx, f[n.lx][n.ly + 1] != '#' ? n.ly + 1 : n.ly,
	      n.rx, f[n.rx][n.ry + 1] != '#' ? n.ry + 1 : n.ry);

      if (!shining(ss, s, W)) {
	q.push(ss);
      }
    }

    if (q.empty()) {
      cout << "No" << endl;
    }
  }

  return 0;
}
