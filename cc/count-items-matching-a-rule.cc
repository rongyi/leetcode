// http://leetcode.com/problems/count-items-matching-a-rule/description/
#include "xxx.hpp"

class Solution {
public:
  int countMatches(vector<vector<string>> &items, string ruleKey,
                   string ruleValue) {
    int idx = -1;
    if (ruleKey == "type") {
      idx = 0;
    } else if (ruleKey == "color") {
      idx = 1;
    } else {
      idx = 2;
    }
    int count = 0;
    for (auto &item : items) {
      if (item[idx] == ruleValue) {
        ++count;
      }
    }

    return count;
  }
};
