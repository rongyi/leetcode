// http://leetcode.com/problems/closest-subsequence-sum/description/
#include "xxx.hpp"

class Solution {
public:
  int minAbsDifference(vector<int> &nums, int goal) {
    const int n = nums.size();
    vector<int> first_half{0};
    vector<int> second_half{0};
    for (int i = 0; i < n / 2; ++i) {
      int curlen = first_half.size();
      for (int j = 0; j < curlen; ++j) {
        first_half.push_back(first_half[j] + nums[i]);
      }
    }
    for (int i = n / 2; i < n; ++i) {
      auto curlen = second_half.size();
      for (int j = 0; j < curlen; ++j) {
        second_half.push_back(second_half[j] + nums[i]);
      }
    }
    set<int> second_set(second_half.begin(), second_half.end());
    int ret = abs(goal); // 最大一个都不取
    for (int i = 0; i < first_half.size(); ++i) {
      auto y = goal - first_half[i];
      // 直到那个点左右再试一下
      auto it = second_set.lower_bound(y);
      if (it != second_set.end()) {
        ret = min(ret, abs(goal - (first_half[i] + *it)));

        auto it2 = it;
        it2++;
        if (it2 != second_set.end()) {
          ret = min(ret, abs(goal - (first_half[i] + *it2)));
        }
      }
      if (it != second_set.begin()) {
        auto it3 = it;
        --it3;
        ret = min(ret, abs(goal - (first_half[i] + *it3)));
      }
    }

    return ret;
  }
};
