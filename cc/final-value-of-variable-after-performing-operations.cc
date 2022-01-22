// https://leetcode.com/problems/final-value-of-variable-after-performing-operations/
#include "xxx.hpp"

class Solution {
public:
  int finalValueAfterOperations(vector<string> &operations) {
    int ret = 0;
    for (auto &op : operations) {
      if (op[1] == '+') {
        ret += 1;
      } else {
        ret -= 1;
      }
    }

    return ret;
  }
};
