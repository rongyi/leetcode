// http://leetcode.com/problems/card-flipping-game/description/
#include "xxx.h"

class Solution {
public:
  // terrible description!
  int flipgame(vector<int> &fronts, vector<int> &backs) {
    unordered_set<int> same;
    for (int i = 0; i < fronts.size(); i++) {
      if (fronts[i] == backs[i]) {
        same.insert(fronts[i]);
      }
    }
    int ret = 3000;
    for (auto num : fronts) {
      if (same.count(num) == 0) {
        ret = min(ret, num);
      }
    }
    for (auto num : backs) {
      if (same.count(num) == 0) {
        ret = min(ret, num);
      }
    }
    return ret % 3000;
  }
};
