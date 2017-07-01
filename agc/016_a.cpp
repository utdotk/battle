#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  string s;
  cin >> s;

  bool f[256] = {};

  int minCnt = 100;
  for (int i = 0; i < s.size(); i++) {
    if (f[s[i]]) {
      continue;
    }

    int cnt = 0;
    int maxCnt = i;
    for (int j = i + 1; j < s.size(); j++) {
      if (s[j] == s[i]) {
	maxCnt = max(cnt, maxCnt);
	cnt = 0;
	continue;
      }

      cnt++;
    }
    minCnt = min(max(cnt, maxCnt), minCnt);
  }

  cout << minCnt << endl;

  return 0;
}
