// http://leetcode.com/problems/number-of-good-ways-to-split-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  int numSplits(string s) {
    const int n = s.size();
    vector<int> left(n - 1, 0);
    // 出于效率考虑把右边的那个省了
    // vector<int> right(n - 1, 0);
    set<char> uniq;
    set<char> uniq2;
    for (int i = 0; i < n - 1; ++i) {
      uniq.insert(s[i]);
      left[i] = uniq.size();
    }
    // i代表下刀切的位置
    uniq.clear();
    int ret = 0;
    for (int i = n - 2; i >= 0; --i) {
      // 刀右边的
      uniq.insert(s[i + 1]);
      // right[i] = uniq.size();

      if (left[i] == uniq.size()) {
        ++ret;
      }
    }

    // for (int i = 0; i < n - 1; ++i) {
    //   if (left[i] == right[i]) {
    //     ++ret;
    //   }
    // }

    return ret;
  }
};
