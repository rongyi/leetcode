// http://leetcode.com/problems/longest-well-performing-interval/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/longest-well-performing-interval/discuss/334897/ChineseC%2B%2B-1124.-O(n)
  int longestWPI(vector<int> &hours) {
    unordered_map<int, int> seen;
    int sum = 0;
    int ret = 0;
    for (int i = 0; i < hours.size(); ++i) {
      sum += hours[i] > 8 ? 1 : -1;
      if (sum > 0) {
        ret = i + 1; // current prefix sum is valid
      } else {
        if (seen.count(sum - 1)) {
          ret = max(ret, i - seen[sum - 1]);
        }
      }
      if (seen.count(sum) == 0) {
        seen[sum] = i;
      }
    }

    return ret;
  }
};
