#include <iostream>
#include <string>
using namespace std;

int main() {
  string A, B;
  cin >> A >> B;
  if (A.size() != B.size()) {
    cout << (A.size() > B.size() ? "GREATER" : "LESS") << endl;
    return 0;
  }
  cout << (A > B ? "GREATER" : A < B ? "LESS" : "EQUAL") << endl;
  return 0;
}
