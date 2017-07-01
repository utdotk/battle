#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  int b = max(D - N, 0);
  int c = max(N - D, 0);
  int a = N - b - c;
  
  string s = "";
  for (int i = 0; i < a; i++) {
    s += 'A';
  }
  for (int i = 0; i < b; i++) {
    s += 'B';
  }
  for (int i = 0; i < c; i++) {
    s += 'C';
  }

  cout << s << endl;

  return 0;
}
