// http://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/description/
#include "xxx.hpp"

class Solution {
public:
  // 又被喷的一逼
  vector<int> maxDepthAfterSplit(string seq) {
    vector<int> ret(seq.size(), 0);
    int level{0};
    int index{0};

    while (index < seq.size()) {
      if (seq[index] == '(') {
        ret[index] = ++level % 2;
      } else {
        ret[index] = level-- % 2;
      }
      index++;
    }

    return ret;
  }
};
