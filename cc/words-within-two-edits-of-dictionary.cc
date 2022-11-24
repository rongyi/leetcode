// https://leetcode.com/problems/words-within-two-edits-of-dictionary/
#include "xxx.hpp"

class Solution {
public:
  vector<string> twoEditWords(vector<string> &queries,
                              vector<string> &dictionary) {
    vector<string> ret;

    for (auto &q : queries) {
      for (auto &d : dictionary) {
        if (editDistance(q, d) <= 2) {
          ret.push_back(q);
          break;
        }
      }
    }

    return ret;
  }
  int editDistance(string &a, string &b) {
    int diff = 0;
    for (int i = 0; i < a.size(); ++i) {
      if (a[i] == b[i]) {
        continue;
      }
      diff++;
    }
    return diff;
  }
};
