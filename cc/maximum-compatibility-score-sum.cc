// https://leetcode.com/problems/maximum-compatibility-score-sum/
#include "xxx.h"

class Solution {
public:
  int maxCompatibilitySum(vector<vector<int>> &students,
                          vector<vector<int>> &mentors) {
    int m = students.size();
    int n = students[0].size();
    vector<int> order(m, 0);
    iota(order.begin(), order.end(), 0);
    int ret = 0;

    auto lambda = [&]() {
      int cur_score = 0;
      for (int i = 0; i < m; ++i) {
        auto &cur_mentor = mentors[i];
        auto &cur_student = students[order[i]];
        for (int j = 0; j < n; ++j) {
          if (cur_mentor[j] == cur_student[j]) {
            cur_score++;
          }
        }
        ret = max(ret, cur_score);
      }
    };

    lambda();
    while (next_permutation(order.begin(), order.end())) {
      lambda();
    }

    return ret;
  }
};
