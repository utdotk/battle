#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B, C;
  cin >> A >> B >> C;

  cout << (A[A.size() - 1] == B[0] &&
	   B[B.size() - 1] == C[0] ? "YES" : "NO") << endl;

  return 0;
}
