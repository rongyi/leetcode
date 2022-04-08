// https://leetcode.com/problems/most-frequent-number-following-key-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  int mostFrequent(vector<int> &nums, int key) {
    int max_num = 0;
    int max_count = 0;
    map<int, int> count;
    for (int i = 1; i < nums.size(); ++i) {
      if (nums[i - 1] == key) {
        ++count[nums[i]];
        if (count[nums[i]] > max_count) {
          max_count = count[nums[i]];
          max_num = nums[i];
        }
      }
    }

    return max_num;
  }
};
