// https://leetcode.com/problems/number-of-laser-beams-in-a-bank/
#include "xxx.hpp"

class Solution {
public:
  int numberOfBeams(vector<string> &bank) {
    int m = bank.size();
    auto laser_fn = [](string &row) -> int {
      int ret = 0;
      for (auto &c : row) {
        if (c == '1') {
          ++ret;
        }
      }

      return ret;
    };

    int prev_count = laser_fn(bank[0]);
    int ret = 0;
    for (int i = 1; i < m; ++i) {
      int cur_count = laser_fn(bank[i]);
      if (cur_count == 0) {
        continue;
      }

      ret += prev_count * cur_count;
      prev_count = cur_count;
    }

    return ret;
  }
};
