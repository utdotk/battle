#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  long hall[] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};

  string s;
  cin >> s;

  long cnt1 = 1;
  for (long i = 0; i < s.size(); i++) {
    cnt1 += 2;
    cnt1 += hall[s[i] - '0'];
  }

  long cnt2 = 2;
  for (long i = 0; i < s.size(); i++) {
    cnt2 += 1;
    cnt2 += hall[s[i] - '0'] * 2;
  }

  cout << min(cnt1, cnt2) << endl;
  return 0;
}
