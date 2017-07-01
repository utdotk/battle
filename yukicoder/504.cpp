#include <iostream>
using namespace std;

int main() {
  int N;
  cin >> N;

  int kp;
  cin >> kp;
  int kr = 1;
  cout << kr << endl;
  for (int i = 1; i < N; i++) {
    int a;
    cin >> a;
    if (a > kp) {
      kr++;
    }
    cout << kr << endl;
  }
  
  return 0;
}
