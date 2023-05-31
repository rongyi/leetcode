// https://leetcode.com/problems/subsequence-with-the-minimum-score/
#include "xxx.hpp"

class Solution {
public:
  int minimumScore(string s, string t) {
    int ssz = s.size();
    int tsz = t.size();
    // suffix
    vector<int> dp(tsz, -1);
    int k = tsz - 1;
    // abacaba
    // bzaa
    // delete z and make baa a subsequence of origin string
    // first, we need to store
    for (int i = ssz - 1; i >= 0 && k >= 0; i--) {
      if (s[i] == t[k]) {
        dp[k--] = i;
      }
    }

    // delete all the front part
    int ret = k + 1;

    for (int i = 0, j = 0; i < ssz && j < tsz && ret > 0; ++i) {
      if (s[i] == t[j]) {
        for (; k < tsz && dp[k] <= i; ++k)
          ;
        ret = min(ret, k - (++j));
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  so.minimumScore("abacaba", "bzaa");
}
