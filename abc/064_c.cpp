#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  vector<bool> flags(8);
  fill(flags.begin(), flags.end(), false);

  int fcnt = 0;
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    int idx = a / 400;
    if (idx >= 8) {
      fcnt++;
      continue;
    }

    flags[idx] = true;
  }

  int ccnt = 0;
  for (int i = 0; i < flags.size(); i++) {
    if (flags[i]) {
      ccnt++;
    }
  }

  cout << max(ccnt, 1) << ' ' << ccnt + fcnt << endl;

  return 0;
}
