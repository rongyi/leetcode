// http://leetcode.com/problems/n-repeated-element-in-size-2n-array/description/
#include "xxx.h"

class Solution {
public:
  int repeatedNTimes(vector<int> &A) {
    unordered_map<int, int> count;
    for (auto num : A) {
      ++count[num];
    }
    for (auto kv : count) {
      if (kv.second == A.size() / 2) {
        return kv.first;
      }
    }
    return -1;
  }
};
