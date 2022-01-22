// http://leetcode.com/problems/remove-duplicate-letters/description/
#include "xxx.hpp"

class Solution {
public:
  string removeDuplicateLetters(string s) {
    unordered_map<char, int> count;
    unordered_map<char, bool> used;
    for (auto c : s) {
      count[c]++;
      used[c] = false;
    }

    string ret{};
    for (auto c : s) {
      // 遇到一个，就递减一个
      count[c]--;

      // 当前使用过这个字符了
      if (used[c]) {
        continue;
      }
      // 如果逆序了，而且这个字符后面还有，那么可以滚蛋了
      while (!ret.empty() && c < ret.back() && count[ret.back()] > 0) {
        used[ret.back()] = false;
        ret.pop_back();
      }

      ret.push_back(c);
      used[c] = true;
    }

    return ret;
  }
};
