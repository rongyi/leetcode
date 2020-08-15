// http://leetcode.com/problems/smallest-subsequence-of-distinct-characters/description/
#include "xxx.h"

class Solution {
public:
  string smallestSubsequence(string text) {
    // 字符出现的次数
    int count[26] = {};
    // 表示该字符有没有出现在结果中
    int used[26] = {};
    string ret;
    for (auto c : text) {
      ++count[c - 'a'];
    }

    for (auto ch : text) {
      --count[ch - 'a'];
      if (used[ch - 'a']) {
        continue;
      }
      ++used[ch - 'a'];

      while (!ret.empty() && ret.back() > ch && count[ret.back() - 'a'] > 0) {
        used[ret.back() - 'a'] = 0;
        ret.pop_back();
      }

      ret.push_back(ch);
    }

    return ret;
  }
};
