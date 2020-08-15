// http://leetcode.com/problems/can-make-palindrome-from-substring/description/
#include "xxx.h"

class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>> &queries) {
    vector<vector<int>> prefix;
    vector<int> cur(26, 0);
    prefix.push_back(cur);
    for (int i = 0; i < s.size(); ++i) {
      ++cur[s[i] - 'a'];
      prefix.push_back(cur);
    }
    vector<bool> ret;
    for (auto const &q : queries) {
      int lo = q[0];
      int hi = q[1];
      int k = q[2];
      vector<int> cur_sum = prefix[hi + 1];

      int diff = 0;
      int sum = hi - lo + 1;
      for (int i = 0; i < 26; ++i) {
        cur_sum[i] -= prefix[lo][i];
        // sum += cur_sum[i];
        diff += (cur_sum[i] % 2);
      }
      // 中间那个可以不用match
      diff -= (sum % 2);

      ret.push_back(diff <= k * 2 ? true : false);
    }

    return ret;
  }
};
