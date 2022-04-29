// https://leetcode.com/problems/sum-of-scores-of-built-strings/
#include "xxx.hpp"

class Solution {
public:
  // first you need to understand what is z function
  // https://cp-algorithms.com/string/z-function.html
  long long sumScores(string s) {
    auto z = zfunc(s);
    return accumulate(z.begin(), z.end(), 0ll) + s.size();
  }

private:
  vector<int> zfunc(string &s) {
    vector<int> z(s.size());
    int l = 0;
    int r = 0;
    for (int i = 1; i < s.size(); ++i) {
      if (i <= r) {
        z[i] = min(r - i + 1, z[i - l]);
      }

      // After having initialized to , we try to increment by running the
      // trivial algorithm -- because in general, after the border , we cannot
      // know if the segment will continue to match or not.
      while (i + z[i] < s.size() && s[z[i]] == s[i + z[i]]) {
        ++z[i];
      }

      if (i + z[i] - 1 > r) {
        l = i;
        r = i + z[i] - 1;
      }
    }

    return z;
  }
};
