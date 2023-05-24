// https://leetcode.com/problems/count-vowel-strings-in-ranges/
#include "xxx.hpp"

class Solution {
public:
  vector<int> vowelStrings(vector<string> &words,
                           vector<vector<int>> &queries) {
    int sz = words.size();
    vector<int> dp(sz + 1, 0);
    // both start and end with vowel?
    auto check = [](string &s) -> bool {
      int sz = s.size();
      if (s[0] == 'a' || s[0] == 'o' || s[0] == 'e' || s[0] == 'i' ||
          s[0] == 'u') {
        return s[sz - 1] == 'a' || s[sz - 1] == 'o' || s[sz - 1] == 'e' ||
               s[sz - 1] == 'i' || s[sz - 1] == 'u';
      }
      return false;
    };
    for (int i = 0; i < sz; i++) {
      dp[i + 1] = dp[i] + check(words[i]);
    }
    vector<int> ret;

    for (auto &q : queries) {
      ret.push_back(dp[q[1] + 1] - dp[q[0]]);
    }

    return ret;
  }
};
