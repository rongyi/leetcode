// https://leetcode.com/problems/number-of-beautiful-pairs/
#include "xxx.hpp"

class Solution {
public:
  int countBeautifulPairs(vector<int> &nums) {
    vector<string> num_strs;
    for (auto &num : nums) {
      num_strs.push_back(to_string(num));
    }
    int ret = 0;
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        int c1 = num_strs[i][0] - '0';
        int c2 = num_strs[j].back() - '0';
        if (__gcd(c1, c2) == 1) {
          ret++;
        }
      }
    }
    return ret;
  }
};
