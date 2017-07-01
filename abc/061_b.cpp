#include <iostream>
#include <vector>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;

  vector<int> roadNums(N);
  fill(roadNums.begin(), roadNums.end(), 0);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;

    roadNums[a - 1]++;
    roadNums[b - 1]++;
  }

  for (int i = 0; i < N; i++) {
    cout << roadNums[i] << endl;
  }

  return 0;
}
