// http://leetcode.com/problems/minimum-moves-to-equal-array-elements/description/
#include "xxx.h"

class Solution {
public:
  // it's a math question
  // https://leetcode.com/problems/minimum-moves-to-equal-array-elements/discuss/93817/It-is-a-math-question
  int minMoves(vector<int> &nums) {
    return accumulate(nums.begin(), nums.end(), 0ll /*int overflow*/) -
           *min_element(nums.begin(), nums.end()) * nums.size();
  }
};
