#include <iostream>
#include <vector>
using namespace std;

void p(const vector<vector<int> > &G) {
  for (int i = 1; i < G.size(); i++) {
    for (int j = 0; j < G[i].size(); j++) {
      cout << G[i][j] << ' ';
    }
    cout << endl;
  }
}

int main() {
  int N, M;
  cin >> N >> M;

  vector<vector<int> > G(N + 1);
  for (int i = 0; i < M; i++) {
    int A, B;
    cin >> A >> B;

    G[A].push_back(B);
    G[B].push_back(A);
  }

  vector<int> P(N * 2 - 1);
  vector<bool> T(N + 1);
  fill(T.begin(), T.end(), false);
  int e1 = N - 1;
  int e2 = N;
  P[e1] = 1;
  P[e2] = G[1][0];
  T[P[e1]] = true;
  T[P[e2]] = true;

  bool flg = false;
  while (!flg) {
    flg = true;
    for (int i = 0; i < G[P[e1]].size(); i++) {
      if (!T[G[P[e1]][i]]) {
	P[e1 - 1] = G[P[e1]][i];
	T[P[e1 - 1]] = true;
	e1--;
	flg = false;
	break;
      }
    }
    for (int i = 0; i < G[P[e2]].size(); i++) {
      if (!T[G[P[e2]][i]]) {
	P[e2 + 1] = G[P[e2]][i];
	T[P[e2 + 1]] = true;
	e2++;
	flg = false;
	break;
      }
    }
  }

  cout << e2 - e1 + 1 << endl;
  for (int i = e1; i <= e2; i++) {
    cout << P[i];
    if (i != e2) {
      cout << ' ';
    }
  }
  cout << endl;
  
  return 0;
}
