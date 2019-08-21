// http://leetcode.com/problems/largest-values-from-labels/description/
#include "xxx.h"

class Solution {
public:
  int largestValsFromLabels(vector<int> &values, vector<int> &labels,
                            int num_wanted, int use_limit) {
    multimap<int, int> nums;
    unordered_map<int, int> count;
    for (auto i = 0; i < values.size(); ++i) {
      nums.insert({values[i], labels[i]});
    }
    int ret = 0;
    for (auto it = nums.rbegin(); it != nums.rend() && num_wanted > 0; ++it) {
      // 每一个label用的次数不超过use_limit
      if (++count[it->second] <= use_limit) {
        ret += it->first;
        --num_wanted;
      }
    }

    return ret;
  }
};
