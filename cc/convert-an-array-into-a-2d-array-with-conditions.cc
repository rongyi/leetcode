// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> findMatrix(vector<int> &nums) {
    map<int, int> cnt;
    int max_freq = 0;
    for (auto &num : nums) {
      cnt[num]++;
      max_freq = max(max_freq, cnt[num]);
    }
    vector<vector<int>> ret(max_freq);
    for (int i = 0; i < max_freq; i++) {
      for (auto &kv : cnt) {
        if (kv.second-- > 0) {
          ret[i].push_back(kv.first);
        }
      }
    }

    return ret;
  }
};
