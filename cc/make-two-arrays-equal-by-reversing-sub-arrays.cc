// http://leetcode.com/problems/make-two-arrays-equal-by-reversing-sub-arrays/description/
#include "xxx.hpp"

class Solution {
public:
  bool canBeEqual(vector<int> &target, vector<int> &arr) {
    // 感觉只要相等就可以了，果不其然
    sort(target.begin(), target.end());
    sort(arr.begin(), arr.end());
    return target == arr;
  }
};
