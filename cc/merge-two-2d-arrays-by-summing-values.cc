// https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> mergeArrays(vector<vector<int>> &nums1,
      vector<vector<int>> &nums2) {
    map<int, int> idval;
    for (auto &num: nums1) {
      idval[num[0]] += num[1];
    }
    for (auto &num: nums2) {
      idval[num[0]] += num[1];
    }
    vector<vector<int>> ret;
    for (auto &kv: idval) {
      ret.push_back({kv.first, kv.second});
    }
    return ret;
  }
};
