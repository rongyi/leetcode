// https://leetcode.com/problems/count-common-words-with-one-occurrence/
#include "xxx.hpp"

class Solution {
public:
  int countWords(vector<string> &words1, vector<string> &words2) {
    map<string, int> count1;
    map<string, int> count2;
    for (auto &w : words1) {
      count1[w]++;
    }
    for (auto &w : words2) {
      count2[w]++;
    }

    int one_count = 0;
    for (auto &kv : count1) {
      if (kv.second == 1 && count2[kv.first] == 1) {
        ++one_count;
      }
    }

    return one_count;
  }
};
