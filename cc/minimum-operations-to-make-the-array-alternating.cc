// https://leetcode.com/problems/minimum-operations-to-make-the-array-alternating/
#include "xxx.hpp"

class Solution {
public:
  int minimumOperations(vector<int> &nums) {
    int sz = nums.size();
    map<int, int> even;
    map<int, int> odd;
    int olen = sz / 2;
    int elen = sz / 2 + (sz & 1);

    for (int i = 0; i < nums.size(); ++i) {
      if (i & 1) {
        ++odd[nums[i]];
      } else {
        ++even[nums[i]];
      }
    }

    int otop_num = -1;
    int otop_freq = 0;
    int osec_freq = 0;
    for (auto &kv : odd) {
      if (kv.second >= otop_freq) {
        // down to the second
        osec_freq = otop_freq;

        otop_num = kv.first;
        otop_freq = kv.second;
      } else if (kv.second >= osec_freq) {
        osec_freq = kv.second;
      }
    }

    int etop_num = -1;
    int etop_freq = 0;
    int esec_freq = 0;
    for (auto &kv : even) {
      if (kv.second >= etop_freq) {
        // down to the second
        esec_freq = etop_freq;

        etop_num = kv.first;
        etop_freq = kv.second;
      } else if (kv.second >= osec_freq) {
        esec_freq = kv.second;
      }
    }

    // 1. change the even pos first
    // keep the most freq, and change the rest in even pos
    // so we get (elen - etop_freq) changes first
    // then we see the odd pos
    int ret1 = elen - etop_freq;
    // if the top odd is the same as top even, we must change all those num in
    // even odd pos,so what we can keep is the secod freq num
    // otop_num must be changed!
    if (otop_num == etop_num) {
      ret1 += (olen - osec_freq);
    } else {
      // we just keep the most freq num in odd pos,
      // so the change is (olen - otop_freq)
      ret1 += (olen - otop_freq);
    }

    // 2. change even pos first
    // same as odd pos first
    int ret2 = olen - otop_freq;
    if (etop_num == otop_num) {
      ret2 += (elen - esec_freq);
    } else {
      ret2 += (elen - etop_freq);
    }
    return min(ret1, ret2);
  }
};
