#include <iostream>
#include <string>
using namespace std;

int main() {
  string S;
  cin >> S;

  long cnt = 0;
  for (int i = 0; i < S.size(); i++) {
    if (S[i] == 'U') {
      cnt += S.size() - i - 1;
      cnt += i * 2;
    } else {
      cnt += i;
      cnt += (S.size() - i - 1) * 2;
    }
  }

  cout << cnt << endl;

  return 0;
}
