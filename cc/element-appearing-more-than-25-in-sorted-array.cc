// http://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array/description/
#include "xxx.hpp"

class Solution {
public:
  int findSpecialInteger(vector<int> &arr) {
    const int total = arr.size();
    unordered_map<int, int> count;
    for (auto &num : arr) {
      ++count[num];
      if (count[num] * 1.0 / total > 0.25) {
        return num;
      }
    }
    // make compiler shutup
    return -1;
  }
};
