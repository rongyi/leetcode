// https://leetcode.com/problems/move-pieces-to-obtain-a-string/
#include "xxx.hpp"

class Solution {
public:
  bool canChange(string start, string target) {
    int i = 0;
    int j = 0;
    int sz = start.size();
    for (; i < sz || j < sz; ++i, ++j) {
      while (i < sz && start[i] == '_') {
        ++i;
      }
      while (j < sz && target[j] == '_') {
        ++j;
      }

      // the L in target must come from the right side: (j <= i)
      // the R in target must come from the left side: (j >= i)
      if (i == sz || j == sz || start[i] != target[j] ||
          (start[i] == 'L' && i < j) || (start[i] == 'R' && i > j)) {
        break;
      }
    }

    return i == sz && j == sz;
  }
};
