#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N;
  cin >> N;

  int cnt = 0;
  vector<int> hist(N);
  fill(hist.begin(), hist.end(), 0);
  for (int i = 0; i < N; i++) {
    int a;
    cin >> a;

    if (hist[a] == 0) {
      cnt++;
    }

    hist[a]++;
  }

  for (int 

  return 0;
}
