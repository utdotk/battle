#include <iostream>
using namespace std;

int main(void) {
  long X, A, B;
  cin >> X >> A >> B;

  if (B <= A) {
    cout << "delicious" << endl;
    return 0;
  }

  if (B - A <= X) {
    cout << "safe" << endl;
    return 0;
  }

  cout << "dangerous" << endl;
  return 0;
}
