// http://leetcode.com/problems/bitwise-ors-of-subarrays/description/
#include "xxx.hpp"

class Solution {
public:
  int subarrayBitwiseORs(vector<int> &A) {
    // 意思是不要算整个子数组的or，先把所有
    // or产生的集合算出来，这样循环的范围会小的多
    unordered_set<int> ret;
    unordered_set<int> cur;
    unordered_set<int> prev;
    for (auto num : A) {
      cur = {num};
      for (auto i : prev) {
        cur.insert(i | num);
      }
      prev = cur;
      for (auto i : cur) {
        ret.insert(i);
      }
    }

    return ret.size();
  }
};
