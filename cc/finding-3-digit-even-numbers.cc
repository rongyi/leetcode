// https://leetcode.com/problems/finding-3-digit-even-numbers/
#include "xxx.hpp"

class Solution {
public:
  vector<int> findEvenNumbers(vector<int> &digits) {
    vector<int> ret;
    int cnt[10] = {};
    for (auto d : digits) {
      cnt[d]++;
    }
    for (int i = 1; i < 10; ++i) {
      if (cnt[i] == 0) {
        continue;
      }
      --cnt[i];
      for (int j = 0; j < 10; ++j) {
        if (cnt[j] == 0) {
          continue;
        }
        --cnt[j];
        for (int k = 0; k < 10; k += 2) {
          if (cnt[k] == 0) {
            continue;
          }
          --cnt[k];
          // find a valid num
          ret.push_back(i * 100 + j * 10 + k);
          // restore the count for next check
          ++cnt[k];
        }
        // restore
        ++cnt[j];
      }
      // restore
      ++cnt[i];
    }

    return ret;
  }
};
