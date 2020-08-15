// http://leetcode.com/problems/minimum-cost-tree-from-leaf-values/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/discuss/339959/One-Pass-O(N)-Time-and-Space
  int mctFromLeafValues(vector<int> &arr) {
    int ret = 0;

    vector<int> stack = {numeric_limits<int>::max()};
    for (auto a : arr) {
      while (stack.back() <= a) {
        int mid = stack.back();
        stack.pop_back();
        ret += mid * min(stack.back(), a);
      }
      stack.push_back(a);
    }
    for (int i = 2; i < stack.size(); ++i) {
      ret += stack[i] * stack[i - 1];
    }
    return ret;
  }
};
