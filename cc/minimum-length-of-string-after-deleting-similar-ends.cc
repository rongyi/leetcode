// http://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/description/
#include "xxx.h"

class Solution {
public:
  int minimumLength(string s) {
    const int n = s.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      if (s[i] == s[j]) {
        auto t = s[i];
        while (i < n && s[i] == t) {
          ++i;
        }
        while (j >= 0 && s[j] == t) {
          --j;
        }
      } else {
        return j - i + 1;
      }
    }
    // 还有一个剩一个的case
    if (i == j) {
      return 1;
    }
    return 0;
  }
};

int main() {
  Solution so;
  so.minimumLength(
      "bbbbbbbbbbbbbbbbbbbbbbbbbbbabbbbbbbbbbbbbbbccbcbcbccbbabbb");
}
