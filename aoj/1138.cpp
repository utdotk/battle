#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct Node {
  int pre;
  int now;
  int tic;
  double tim;

  Node(int p, int n, int tc, double tm) {
    pre = p;
    now = n;
    tic = tc;
    tim = tm;
  }

  bool operator<(const Node &n) const {
    return tim > n.tim;
  }
};

int main() {
  while (true) {
    int n, m, p, a, b;
    cin >> n >> m >> p >> a >> b;

    if (n == 0) {
      break;
    }

    vector<int> t(n);
    for (int i = 0; i < n; i++) {
      cin >> t[i];
    }

    vector<vector<int> > z(m + 1);
    for (int i = 1; i <= m; i++) {
      z[i].resize(m + 1);
      fill(z[i].begin(), z[i].end(), -1);
    }

    for (int i = 1; i <= p; i++) {
      int x, y;
      cin >> x >> y;
      cin >> z[x][y];
      z[y][x] = z[x][y];
    }

    bool f[31][256];
    for (int i = 1; i <= 30; i++) {
      for (int j = 0; j < 256; j++) {
	f[i][j] = false;
      }
    }

    priority_queue<Node> q;
    Node sn(a, a, 0xFF, 0.0);
    q.push(sn);
    while (!q.empty()) {
      Node nd = q.top();

      if (nd.now == b) {
	cout << nd.tim << endl;
	break;
      }
      q.pop();

      if (f[nd.now][nd.tic]) {
	continue;
      }
      f[nd.now][nd.tic] = true;

      for (int i = 1; i <= m; i++) {
	if (z[nd.now][i] != -1) {
	  for (int j = 0; j < n; j++) {
	    int bit = 1 << j;
	    if (nd.tic & bit) {
	      Node nn(nd.now, i, nd.tic & ~bit,
		      nd.tim + (double)z[nd.now][i] / t[j]);
	      q.push(nn);
	    }
	  }
	}
      }
    }

    if (q.empty()) {
      cout << "Impossible" << endl;
    }
  }

  return 0;
}
