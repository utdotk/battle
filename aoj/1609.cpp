#include <iostream>
using namespace std;

const int N = 100;

int main() {
  int n;

  while (cin >> n, n != 0) {
    char f[N];
    for (int i = 0; i < n; i++) {
      cin >> f[i];
    }

    int cnt[26] = {};
    char c1 = 'A';
    char c2 = 'B';

    for (int i = 0; i < n; i++) {
      cnt[f[i] - 'A']++;
      if (cnt[f[i] - 'A'] > cnt[c2 - 'A'] && f[i] != c1) {
	c2 = f[i];
      }

      if (cnt[c2 - 'A'] > cnt[c1 - 'A']) {
	char tmp = c1;
	c1 = c2;
	c2 = tmp;
      }

      if (cnt[c1 - 'A'] > cnt[c2 - 'A'] + n - i - 1) {
	cout << c1 << ' ' << i + 1 << endl;
	break;
      }

      if (i == n - 1) {
	cout << "TIE" << endl;
      }
    }
  }

  return 0;
}
