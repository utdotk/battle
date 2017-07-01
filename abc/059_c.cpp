#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

long sign(long x) {
  return x < 0 ? -1 : 1;
}

int main() {
  long n;
  cin >> n;

  vector<long> A(n);
  for (long i = 0; i < n; i++) {
    cin >> A[i];
  }

  long cnt = 0;
  long sum = A[0];
  if (sum <= 0) {
    cnt += abs(sum) + 1;
    sum = 1;
  }
  for (long i = 1; i < n; i++) {
    long a = A[i];
    long newsum = sum + a;
    if (sign(sum) == sign(newsum) || newsum == 0) {
      cnt += abs(newsum) + 1;
      newsum = -sign(sum);
    }
    sum = newsum;
  }
  
  long cnt2 = 0;
  long sum2 = A[0];
  if (sum2 >= 0) {
    cnt2 += abs(sum2) + 1;
    sum2 = -1;
  }
  for (long i = 1; i < n; i++) {
    long a = A[i];
    long newsum = sum2 + a;
    if (sign(sum2) == sign(newsum) || newsum == 0) {
      cnt2 += abs(newsum) + 1;
      newsum = -sign(sum2);
    }
    sum2 = newsum;
  }
  
  cout << min(cnt, cnt2) << endl;
  
  return 0;
}
