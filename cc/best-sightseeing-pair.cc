// http://leetcode.com/problems/best-sightseeing-pair/description/
#include "xxx.hpp"

class Solution {
public:
  int maxScoreSightseeingPair(vector<int> &A) {
    int maxi = A[0] - 1;
    int ret = 0;
    for (int j = 1; j < A.size(); j++, --maxi) {
      ret = max(ret, A[j] + maxi);
      // 可以从j这里开始吗？
      maxi = max(maxi, A[j]);
    }

    return ret;
  }
};
