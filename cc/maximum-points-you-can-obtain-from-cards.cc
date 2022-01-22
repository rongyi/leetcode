// http://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/description/
#include "xxx.hpp"

class Solution {
public:
  int maxScore(vector<int> &cardPoints, int k) {
    if (k == cardPoints.size()) {
      return accumulate(begin(cardPoints), end(cardPoints), 0);
    }
    int ret = accumulate(begin(cardPoints), begin(cardPoints) + k, 0);
    int cur = ret;
    for (int i = k - 1, j = cardPoints.size() - 1; i >= 0 && j >= 0; --i, --j) {
      cur = cur - cardPoints[i] + cardPoints[j];
      ret = max(ret, cur);
    }
    return ret;
  }
};
