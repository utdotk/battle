#include <iostream>
#include <vector>
using namespace std;

int main(void) {
  int N;
  cin >> N;

  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  int ans = -1;
  int i = 1;
  for (int j = 1; j <= N; j++) {
    i = a[i - 1];
    if (i == 2) {
      ans = j;
      break;
    }
  }

  cout << ans << endl;

  return 0;
}
