// http://leetcode.com/problems/check-if-word-equals-summation-of-two-words/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSumEqual(string firstWord, string secondWord, string targetWord) {
    auto tonum = [](string &s) -> int {
      string ns;
      for (auto c : s) {
        ns.push_back('0' + (c - 'a'));
      }
      int i = 0;
      int sz = ns.size();
      while (i < sz && ns[i] == '0') {
        i++;
      }
      if (i == sz) {
        return 0;
      }
      return stoi(ns.substr(i));
    };

    return (tonum(firstWord) + tonum(secondWord)) == tonum(targetWord);
  }
};
