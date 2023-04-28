// http://leetcode.com/problems/h-index/description/
#include "xxx.hpp"

class Solution {
public:
  int hIndex(vector<int> &citations) {
    int sz = citations.size();
    // if one paper's citation is too big, we put it
    // in the last index;
    vector<int> ref_cnt(sz + 1, 0);
    for (auto &c : citations) {
      if (c >= sz) {
        ref_cnt[sz]++;
      } else {
        ref_cnt[c]++;
      }
    }
    // h index means: h paper each citation >= h
    int paper_cnt = 0;
    for (int i = sz; i >= 0; i--) {
      paper_cnt += ref_cnt[i];
      if (paper_cnt >= i) {
        return i;
      }
    }
    return 0;
  }
};
