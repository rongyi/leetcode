// https://leetcode.com/problems/separate-the-digits-in-an-array/
#include "xxx.hpp"

class Solution {
public:
  vector<int> separateDigits(vector<int> &nums) {
    auto tod = [](int num) -> vector<int> {
      vector<int> ret;
      if (num == 0) {
        ret.push_back(0);
        return ret;
      }
      while (num) {
        ret.push_back(num % 10);
        num /= 10;
      }
      reverse(ret.begin(), ret.end());
      return ret;
    };
    vector<int> ret;
    for (auto &num : nums) {
      auto ds = tod(num);
      ret.insert(ret.end(), ds.begin(), ds.end());
    }

    return ret;
  }
};
