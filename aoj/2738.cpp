#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  cin >> N;

  bool yes = true;
  int acnt = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    if (s[0] == 'A') {
      acnt++;
    } else if (s[0] == 'U') {
      if (acnt == 0) {
	yes = false;
      }
      acnt--;
    }
  }

  cout << (acnt == 0 && yes ? "YES" : "NO") << endl;

  return 0;
}
