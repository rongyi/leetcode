// https://leetcode.com/problems/longest-subsequence-repeated-k-times/
#include "xxx.h"
class Solution {
public:
  string longestSubsequenceRepeatedK(string &s, int k) {
    for (char c = 'a'; c <= 'z'; ++c) {
      dfs({c}, s, k);
    }
    return best_;
  }

private:
  void dfs(string sub, string &s, int k) {
    if (count_occ(sub, s) < k) {
      return;
    }
    if (sub.size() >= best_.size() && sub > best_) {
      best_ = sub;
    }
    for (char c = 'a'; c <= 'z'; ++c) {
      dfs(sub + c, s, k);
    }
  }
  int count_occ(string &sub, string &s) {
    int cnt = 0;
    int j = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (sub[j] == s[i]) {
        j++;
        // ok match a subsequence, start over again
        if (j == sub.size()) {
          j = 0;
          cnt++;
        }
      }
    }

    return cnt;
  }

private:
  string best_;
};
int main() {
  Solution so;
  string input{"letsleetcode"};
  so.longestSubsequenceRepeatedK(input, 2);
}
