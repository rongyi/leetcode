// https://leetcode.com/problems/longest-subsequence-with-limited-sum/
#include "xxx.hpp"

class Solution {
public:
  vector<int> answerQueries(vector<int> &nums, vector<int> &queries) {
    int m = nums.size();
    int n = queries.size();
    sort(nums.begin(), nums.end());

    vector<int> ret(n, 0);
    vector<int> prefix(m + 1, 0);
    for (int i = 0; i < m; ++i) {
      prefix[i + 1] = prefix[i] + nums[i];
    }
    for (int i = 0; i < n; ++i) {
      auto it = upper_bound(prefix.begin(), prefix.end(), queries[i]);
      // prefix[0] is not used
      ret[i] = distance(prefix.begin(), it) - 1;
    }

    return ret;
  }
};
