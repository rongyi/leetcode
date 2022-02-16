// https://leetcode.com/problems/find-good-days-to-rob-the-bank/
#include "xxx.hpp"

class Solution {
public:
  vector<int> goodDaysToRobBank(vector<int> &security, int time) {
    int sz = security.size();
    if (time == 0) {
      vector<int> ret(sz, 0);
      iota(ret.begin(), ret.end(), 0);
      return ret;
    }
    vector<int> ret;
    vector<bool> from_left(sz, false);
    vector<bool> from_right(sz, false);

    for (int i = 1, cur_mono = 1; i < sz; ++i) {
      if (security[i] <= security[i - 1]) {
        cur_mono++;
        if (cur_mono > time) {
          from_left[i] = true;
        }
      } else {
        // reset
        cur_mono = 1;
      }
    }
    for (int i = sz - 2, cur_mono = 1; i >= 0; --i) {
      if (security[i] <= security[i + 1]) {
        cur_mono++;
        if (cur_mono > time) {
          from_right[i] = true;
        }
      } else {
        cur_mono = 1;
      }
    }
    for (int i = 0; i < sz; ++i) {
      if (from_left[i] && from_right[i]) {
        ret.push_back(i);
      }
    }
    return ret;
  }
};
