// http://leetcode.com/problems/frog-jump/description/
#include "xxx.h"

class Solution {
public:
  bool canCross(vector<int> &stones) { return canCross(stones, 0, 0); }

public:
  bool canCross(vector<int> &stones, int pos, int k) {
    int key = pos | (k << 11);

    if (dp_.count(key) > 0) {
      return dp_[key];
    }
    for (int i = pos + 1; i < stones.size(); ++i) {
      int gap = stones[i] - stones[pos];
      if (gap < k - 1) {
        continue;
      }
      if (gap > k + 1) {
        dp_[key] = false;
        return false;
      }
      if (canCross(stones, i, gap)) {
        dp_[key] = true;
        return true;
      }
    }
    dp_[key] = (pos == int(stones.size() - 1));
    return dp_[key];
  }

private:
  unordered_map<int, int> dp_;
};
