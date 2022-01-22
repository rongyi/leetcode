// http://leetcode.com/problems/sort-array-by-increasing-frequency/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> frequencySort(vector<int> &nums) {
    unordered_map<int, int> count;
    for (auto &n : nums) {
      count[n]++;
    }
    sort(nums.begin(), nums.end(), [&count](int &l, int &r) -> bool {
      if (count[l] == count[r]) {
        return l > r;
      }
      return count[l] < count[r];
    });

    return nums;
  }
};
