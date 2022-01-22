// http://leetcode.com/problems/merge-triplets-to-form-target-triplet/description/
#include "xxx.hpp"

class Solution {
public:
  bool mergeTriplets(vector<vector<int>> &triplets, vector<int> &target) {
    vector<int> ret(3, 0);

    for (auto &t : triplets) {
      if (t[0] <= target[0] && t[1] <= target[1] && t[2] <= target[2]) {
        ret[0] = max(ret[0], t[0]);
        ret[1] = max(ret[1], t[1]);
        ret[2] = max(ret[2], t[2]);
      }
    }

    return ret == target;
  }
};
