// https://leetcode.com/problems/bitwise-xor-of-all-pairings/
#include "xxx.hpp"

class Solution {
public:
  int xorAllNums(vector<int> &nums1, vector<int> &nums2) {
    auto all = [](vector<int> &nums) {
      int ret = 0;
      for (auto num : nums) {
        ret ^= num;
      }
      return ret;
    };
    auto num1 = all(nums1);
    auto num2 = all(nums2);
    int sz1 = nums1.size();
    int sz2 = nums2.size();
    bool sz1_isodd = (sz1 & 1);
    bool sz2_isodd = (sz2 & 1);

    if (sz1_isodd && sz2_isodd) {
      return num1 ^ num2;
    }
    if (sz1_isodd) {
      return num2;
    }
    if (sz2_isodd) {
      return num1;
    }
    return 0;
  }
};
