// http://leetcode.com/problems/longest-chunked-palindrome-decomposition/description/
#include "xxx.h"

class Solution {
public:
  int longestDecomposition(string text) {
    if (text.empty()) {
      return 0;
    }
    const int n = text.size();
    for (int i = 0; i < n / 2; ++i) {
      auto left = text.substr(0, i + 1);
      auto right = text.substr(n - i - 1, i + 1);
      if (left == right) {
        auto inner = text.substr(i + 1, n - 2 * (i + 1));
        return 2 + longestDecomposition(inner);
      }
    }

    return 1;
  }
};
