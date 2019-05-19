// http://leetcode.com/problems/split-array-with-same-average/description/
#include "xxx.h"

class Solution {
public:
  bool splitArraySameAverage(vector<int> &A) {
    const int n = A.size();
    int m = n / 2;
    int total_sum = accumulate(A.begin(), A.end(), 0);
    bool is_possible = false;
    for (int i = 0; i <= m && !is_possible; i++) {
      if (total_sum * i % n == 0) {
        is_possible = true;
      }
    }
    if (!is_possible) {
      return false;
    }
    vector<unordered_set<int>> sums(m + 1);
    sums[0].insert(0);
    for (auto num : A) {
      for (int i = m; i >= 1; --i) {
        for (const int t : sums[i - 1]) {
          sums[i].insert(t + num);
        }
      }
    }
    for (int i = 1; i <= m; i++) {
      if (total_sum * i % n == 0 &&
          sums[i].find(total_sum * i / n) != sums[i].end()) {
        return true;
      }
    }
    return false;
  }
};
