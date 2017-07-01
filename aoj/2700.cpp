#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }

    vector<string> s(n);
    for (int i = 0; i < n; i++) {
      cin >> s[i];
    }

    vector<string> c(n);
    for (int i = 0; i < n; i++) {
      c[i] += s[i][0];
      char last = s[i][0];
      for (int j = 1; j < s[i].size(); j++) {
	if (last == 'a' || last == 'e' || last == 'i' ||
	    last == 'o' || last == 'u') {
	  c[i] += s[i][j];
	}
	last = s[i][j];
      }
    }

    int l = 0;
    for (int i = 0; i < n; i++) {
      if (c[i].size() > l) {
	l = c[i].size();
      }
    }

    bool f = false;
    for (int k = 1; k <= l && !f; k++) {
      map<string, bool> m;
      for (int i = 0; i < n; i++) {
	string sc = c[i].substr(0, k < c[i].size() ? k : c[i].size());
	if (m.count(sc) != 0) {
	  break;
	}
	if (i == n - 1) {
	  cout << k << endl;
	  f = true;
	  break;
	}
	m[sc] = true;
      }
    }

    if (!f) {
      cout << -1 << endl;
    }
  }

  return 0;
}
