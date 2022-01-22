// http://leetcode.com/problems/reverse-string-ii/description/
#include "xxx.hpp"

class Solution {
public:
  string reverseStr(string s, int k) {
    int i = 0;
    bool should_reverse = true;
    stringstream ss;
    const int n = s.size();
    while (i < n) {
      string part = s.substr(i, k);
      if (should_reverse) {
        reverse(part.begin(), part.end());
      }

      ss << part;
      should_reverse = !should_reverse;
      i += k;
    }
    return ss.str();
  }
};

int main() {
  Solution so;
  auto ret = so.reverseStr("abcdefg", 2);
  cout << ret << endl;
}
