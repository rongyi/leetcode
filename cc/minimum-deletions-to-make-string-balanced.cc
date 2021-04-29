// http://leetcode.com/problems/minimum-deletions-to-make-string-balanced/description/
#include "xxx.h"

class Solution {
public:
  int minimumDeletions(string s) {
    vector<int> dp(s.size() + 1, 0);
    int bcount = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == 'a') {
        // 1. delete current a => dp[i] + 1
        // 2. keep current a => delete all b befire this a
        dp[i + 1] = min(dp[i] + 1, bcount);
      } else {
        bcount++;
        dp[i + 1] = dp[i];
      }
    }
    return dp[s.size()];
  }
};

int main() {
  Solution so;
  auto ret = so.minimumDeletions(
      "ababaaaabbbbbaaababbbbbbaaabbaababbabbbbaabbbbaabbabbabaabbbababaa");
  cout << ret << endl;
}
