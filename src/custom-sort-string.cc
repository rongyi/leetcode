// https://leetcode.com/problems/custom-sort-string/description/
#include "xxx.h"

class Solution {
public:
  string customSortString2(string S, string T) {
    std::string ret = T;
    std::unordered_map<char, int> order;
    for (int i = 0; i < S.size(); i++) {
      order[S[i]] = i + 1;
    }
    std::sort(ret.begin(), ret.end(),
              [&](char a, char b) { return order[a] < order[b]; });
    return ret;
  }
  string customSortString(string S, string T) {
    std::string ret;
    std::unordered_map<char, int> count;
    for (auto c : T) {
      ++count[c];
    }

    for (auto c : S) {
      ret += string(count[c], c);
      count[c] = 0;
    }

    for (auto c : count) {
      ret += string(c.second, c.first);
    }

    return ret;
  }
};
