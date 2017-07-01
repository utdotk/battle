#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
  while (true) {
    int n;
    cin >> n;

    if (n == 0) {
      break;
    }
    
    vector<string> w(n);
    for (int i = 0; i < n; i++) {
      cin >> w[i];
    }

    int cnt1 = 0;
    int cnt2 = 0;
    for (int i = 0; i < n; i++) {
      for (int j = i; j < n; j++) {
	cnt2 += w[j].size();
	if ((cnt1 == 0 || cnt1 == 2) && cnt2 > 5 || cnt2 > 7) {
	  cnt1 = 0;
	  cnt2 = 0;
	  break;
	}

	if ((cnt1 == 0 || cnt1 == 2) && cnt2 == 5 ||
	    (cnt1 == 1 || cnt1 == 3) && cnt2 == 7) {
	  cnt1++;
	  cnt2 = 0;
	}
	if (cnt1 == 4 && cnt2 == 7) {
	  cout << i + 1 << endl;
	  i = n;
	  break;
	}
      }
    }
  }

  return 0;
}
