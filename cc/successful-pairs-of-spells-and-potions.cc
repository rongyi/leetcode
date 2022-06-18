// https://leetcode.com/problems/successful-pairs-of-spells-and-potions/
#include "xxx.hpp"

class Solution {
public:
  vector<int> successfulPairs(vector<int> &spells, vector<int> &potions,
                              long long success) {
    sort(potions.begin(), potions.end());
    vector<int> ret;

    for (int i = 0; i < spells.size(); ++i) {
      long long p = success / spells[i];
      if ((success % spells[i]) != 0) {
        p += 1;
      }
      auto it = lower_bound(potions.begin(), potions.end(), p);
      int cnt = distance(it, potions.end());
      ret.push_back(cnt);
    }

    return ret;
  }
};
