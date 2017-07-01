#include <iostream>
using namespace std;

int main() {
  int A, B, C;
  cin >> A >> B >> C;
  cout << (C >= A && C <= B  ? "Yes" : "No") << endl;
  return 0;
}
