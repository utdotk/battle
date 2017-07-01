#include <iostream>
using namespace std;

const int val[] = {0, 1, 3, 1, 2, 1, 2, 1, 1, 2, 1, 2, 1};

int main() {
  int x, y;
  cin >> x >> y;

  cout << (val[x] == val[y] ? "Yes" : "No") << endl;

  return 0;
}
