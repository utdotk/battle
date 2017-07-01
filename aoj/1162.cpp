#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Node {
public:
  int pre;
  int now;
  int vel;
  double time;

  Node(int p, int n, int v, double t) {
    pre = p;
    now = n;
    vel = v;
    time = t;
  }

  bool operator<(const Node &n) const {
    return time > n.time;
  }
};

int main() {
  while (true) {
    int n, m;
    cin >> n >> m;

    if (n == 0) {
      break;
    }

    int s, g;
    cin >> s >> g;

    vector<vector<int> > d(n + 1), c(n + 1);
    for (int i = 0; i <= n; i++) {
      d[i].resize(n + 1);
      c[i].resize(n + 1);
      fill(d[i].begin(), d[i].end(), -1);
      fill(c[i].begin(), c[i].end(), 0);
    }

    for (int i = 0; i < m; i++) {
      int x, y;
      cin >> x >> y;
      cin >> d[x][y] >> c[x][y];
      d[y][x] = d[x][y];
      c[y][x] = c[x][y];
    }

    bool f[31][31][31];
    for (int i = 0; i < 31; i++) {
      for (int j = 0; j < 31; j++) {
	for (int k = 0; k < 31; k++) {
	  f[i][j][k] = false;
	}
      }
    }
  
    bool goal = false;
    Node snd(0, s, 0, 0.0);
    priority_queue<Node> q;
    q.push(snd);
    while (!q.empty()) {
      Node nd = q.top();
      q.pop();
      if (nd.now == g && nd.vel == 1) {
	goal = true;
	cout << nd.time << endl;
	break;
      }
      if (f[nd.pre][nd.now][nd.vel]) {
	continue;
      }
      f[nd.pre][nd.now][nd.vel] = true;
      for (int i = 1; i <= n; i++) {
	if (i != nd.pre && d[nd.now][i] != -1) {
	  for (int j = -1; j <= 1; j++) {
	    int vel = nd.vel + j;
	    if (vel > 0 && vel <= c[nd.now][i]) {
	      Node next(nd.now, i, vel, nd.time + (double)d[nd.now][i] / vel);
	      q.push(next);
	    }
	  }
	}
      }
    }

    if (!goal) {
      cout << "unreachable" << endl;
    }
  }

  return 0;
}
