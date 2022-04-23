// https://leetcode.com/problems/find-the-difference-of-two-arrays/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findDifference(vector<int> &nums1, vector<int> &nums2) {
    set<int> uniq1(nums1.begin(), nums1.end());
    set<int> uniq2(nums2.begin(), nums2.end());

    vector<int> ret1;
    vector<int> ret2;

    for (auto &k : uniq1) {
      if (!uniq2.count(k)) {
        ret1.push_back(k);
      }
    }
    for (auto &k : uniq2) {
      if (!uniq1.count(k)) {
        ret2.push_back(k);
      }
    }

    return {ret1, ret2};
  }
};
