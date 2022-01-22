// http://leetcode.com/problems/is-subsequence/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSubsequence(string s, string t) {
    if (s.empty()) {
      return true;
    }
    int j = 0;
    const int m = s.size();
    const int n = t.size();

    for (int i = 0; i < n; i++) {
      if (s[j] == t[i]) {
        j++;
      }

      if (j == m) {
        return true;
      }
    }

    return false;
  }
};

int main() {
  Solution so;
  auto ret = so.isSubsequence("abc", "ahbgdc");
  cout << ret << endl;
}
