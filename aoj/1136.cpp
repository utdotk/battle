#include <iostream>
#include <vector>
using namespace std;

struct Point {
  int x, y;
};

struct Line {
  int i;
  vector<Point> ps;
};

void turn(Line &l) {
  for (int i = 0; i < l.ps.size(); i++) {
    int tmp = l.ps[i].x;
    l.ps[i].x = - l.ps[i].y;
    l.ps[i].y = tmp;
  }
}

void normal(Line &l) {
  int x = l.ps[0].x;
  int y = l.ps[0].y;
  for (int i = 0; i < l.ps.size(); i++) {
    l.ps[i].x -= x;
    l.ps[i].y -= y;
  }
}

void reverse(Line &l) {
  int m = l.ps.size();
  for (int i = 0; i < m / 2; i++) {
    Point tmp = l.ps[i];
    l.ps[i] = l.ps[m - i - 1];
    l.ps[m - i - 1] = tmp;
  }
}

int main() {
  int n;
  while (cin >> n, n != 0) {
    vector<Line> lines;
    lines.reserve((n + 1) * 8);
    for (int i = 0; i <= n; i++) {
      int m;
      cin >> m;

      Line l;
      l.i = i;
      l.ps.resize(m);
      for (int j = 0; j < m; j++) {
	cin >> l.ps[j].x >> l.ps[j].y;
      }
      normal(l);
      lines.push_back(l);
      reverse(l);
      normal(l);
      lines.push_back(l);

      for (int j = 0; j < 3; j++) {
	turn(l);
	normal(l);
	lines.push_back(l);
	reverse(l);
	normal(l);
	lines.push_back(l);
      }
    }

    Line line = lines[0];
    for (int i = 1; i <= n; i++) {
      if (line.ps.size() != lines[i * 8].ps.size()) {
	continue;
      }
      for (int j = i * 8; j < (i + 1) * 8; j++) {
	bool flag = false;
	Line l = lines[j];
	for (int k = 0; k < l.ps.size(); k++) {
	  if (l.ps[k].x != line.ps[k].x || l.ps[k].y != line.ps[k].y) {
	    break;
	  }
	  if (k == l.ps.size() - 1) {
	    cout << l.i << endl;
	    flag = true;
	  }
	}
	if (flag) {
	  break;
	}
      }
    }

    cout << "+++++" << endl;
  }

  return 0;
}
