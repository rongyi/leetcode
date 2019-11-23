// http://leetcode.com/problems/replace-the-substring-for-balanced-string/description/
#include "xxx.h"

class Solution {
public:
  int balancedString(string s) {
    unordered_map<char, int> count;
    const int n = s.size();
    const int k = n / 4;
    int ret = n;
    for (auto &c : s) {
      ++count[c];
    }
    int i = 0;
    for (int j = 0; j < n; ++j) {
      --count[s[j]];
      while (i < n && count['Q'] <= k && count['W'] <= k && count['E'] <= k &&
             count['R'] <= k) {
        ret = min(ret, j - i + 1);
        count[s[i++]] += 1;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.balancedString("QWER");
}
