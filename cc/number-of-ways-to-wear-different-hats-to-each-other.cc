// http://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/description/
#include "xxx.h"

class Solution {
public:
  int numberWays(vector<vector<int>> &hats) {
    // total person
    const int n = hats.size();
    // has -> persons
    vector<vector<int>> persons(40);
    const int mod = 1e9 + 7;

    vector<int> masks(1 << n);
    masks[0] = 1;

    for (int i = 0; i < n; ++i) {
      for (auto &h : hats[i]) {
        persons[h - 1].push_back(i);
      }
    }

    for (int i = 0; i < 40; ++i) {
      for (int j = (1 << n) - 1; j >= 0; --j) {
        for (auto &p : persons[i]) {
          if ((j & (1 << p)) == 0) {
            masks[j | (1 << p)] += masks[j];
            masks[j | (1 << p)] %= mod;
          }
        }
      }
    }

    return masks[(1 << n) - 1];
  }
};
