// https://leetcode.com/problems/odd-string-difference/
#include "xxx.hpp"

class Solution {
public:
  string oddString(vector<string> &words) {
    int wlen = words[0].size();
    int rows = words.size();
    for (int j = 0; j < wlen - 1; ++j) {
      map<int, int> cnt;
      // need to remember the index
      map<int, int> idx;
      for (int i = 0; i < rows; ++i) {
        int diff = words[i][j + 1] - words[i][j];
        cnt[diff]++;
        // update the index, multiple value index is useless
        idx[diff] = i;
      }
      if (cnt.size() != 1) {
        for (auto &kv : cnt) {
          if (kv.second == 1) {
            return words[idx[kv.first]];
          }
        }
      }
    }

    return "";
  }
};
