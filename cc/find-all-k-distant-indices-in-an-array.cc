// https://leetcode.com/problems/find-all-k-distant-indices-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findKDistantIndices(vector<int> &nums, int key, int k) {
    vector<int> idx;
    int sz = nums.size();
    for (int i = 0; i < sz; ++i) {
      if (nums[i] == key) {
        idx.push_back(i);
      }
    }
    vector<int> ret;

    for (auto center : idx) {
      for (int i = max(0, center - k); i <= min(sz - 1, center + k); ++i) {
        // ensure the index is uniq
        if (ret.empty() || ret.back() < i) {
          ret.push_back(i);
        }
      }
    }

    return ret;
  }
};
