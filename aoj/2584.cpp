#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

char letter(const string &s, int &p);
string srting(const string &s, int &p);
string cipher(const string &s, int &p);

char letter(const string &s, int &p) {
  if (s[p] == '?' || s[p] >= 'A' && s[p] <= 'Z') {
    p++;
    return s[p - 1];
  }

  int q = p;
  p++;
  char l = letter(s, p);

  if (s[q] == '+') {
    return l == '?' ? '?' : l != 'Z' ? l + 1 : 'A';
  }

  if (s[q] == '-') {
    return l == '?' ? '?' : l != 'A' ? l - 1 : 'Z';
  }
}

string srting(const string &s, int &p) {
  if (s[p] != '[') {
    return string() + letter(s, p);
  }

  p++;
  string c = cipher(s, p);
  p++;
  std::reverse(c.begin(), c.end());

  return c;
}

string cipher(const string &s, int &p) {
  string c = srting(s, p);

  if (s[p] == ']' || p == s.size()) {
    return c;
  }

  c += cipher(s, p);

  return c;
}

int main() {
  string s;
  while (cin >> s, s != ".") {
    int p = 0;
    string c = cipher(s, p);
    replace(c.begin(), c.end(), '?', 'A');

    cout << c << endl;
  }

  return 0;
}
