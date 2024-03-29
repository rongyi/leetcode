// https://leetcode.com/problems/jewels-and-stones/description/
#include "xxx.hpp"

class Solution {
public:
  int numJewelsInStones(string J, string S) {
    unordered_map<char, int> count;
    for (auto c : S) {
      ++count[c];
    }
    int ret = 0;
    for (auto j : J) {
      ret += count[j];
    }

    return ret;
  }
};
