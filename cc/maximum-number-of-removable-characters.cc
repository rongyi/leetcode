// http://leetcode.com/problems/maximum-number-of-removable-characters/description/
#include "xxx.hpp"

class Solution {
public:
  int maximumRemovals(string s, string p, vector<int> &removable) {
    int l = 0;
    int r = removable.size();
    while (l <= r) {
      auto mid = (l + r) / 2;
      if (valid(s, p, removable, mid)) {
        l = mid + 1;
      } else {
        r = mid - 1;
      }
    }
    return r;
  }

private:
  bool valid(string &s, string &p, vector<int> &rm, int k) {
    memset(black_, 0, sizeof(black_));
    for (int i = 0; i < k; ++i) {
      // the remove index;
      black_[rm[i]] = 1;
    }
    int m = s.size();
    int n = p.size();
    int j = 0;
    for (int i = 0; i < m && j < n; ++i) {
      if (black_[i] == 1) {
        continue;
      }
      if (s[i] == p[j]) {
        ++j;
      }
    }

    return j == n;
  }

private:
  int black_[100001];
};
