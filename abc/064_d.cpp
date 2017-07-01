#include <iostream>
#include <string>
using namespace std;

int main() {
  int N;
  string S;
  cin >> N >> S;

  int l = 0;
  int r = 0;
  for (int i = 0; i < N; i++) {
    if (S[i] == '(') {
      r++;
    }
    if (S[i] == ')') {
      if (r > 0) {
	r--;
      } else {
	l++;
      }
    }
  }

  for (int i = 0; i < l; i++) {
    cout << '(';
  }
  cout << S;
  for (int i = 0; i < r; i++) {
    cout << ')';
  }
  cout << endl;

  return 0;
}
