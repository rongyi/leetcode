// http://leetcode.com/problems/single-number-iii/description/
#include "simpleone.h"

class Solution {
public:
  vector<int> singleNumber(vector<int> &nums) {
    auto pivot = simple(nums);
    // ret这个值现在就是这两个不同的值异或的结果，从里面找一位出来然后
    // 以此标记为把数组分为两个，这样问题就化简为之前一个数组中出现一次的那种了
    int i = 0;
    for (; i < sizeof(int) * 8; i++) {
      if ((pivot >> i) & 0x1) {
        break;
      }
    }
    // 现在以i位开始劈开
    vector<int> nums1;
    vector<int> nums2;
    for (auto num : nums) {
      if ((num >> i) & 0x1) {
        nums1.push_back(num);
      } else {
        nums2.push_back(num);
      }
    }
    return vector<int>{simple(nums1), simple(nums2)};
  }
private:
  // sometimes naiive
  int simple(vector<int> &nums) {
    int ret = 0;
    for (auto i : nums){
      ret ^= i;
    }
    return ret;
  }
};
