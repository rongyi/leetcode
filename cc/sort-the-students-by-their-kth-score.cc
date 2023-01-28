// https://leetcode.com/problems/sort-the-students-by-their-kth-score/
#include "xxx.hpp"

class Solution {
public:
  vector<vector<int>> sortTheStudents(vector<vector<int>> &score, int k) {
    sort(score.begin(), score.end(),
         [&](vector<int> &l, vector<int> &r) { return l[k] > r[k]; });

    return score;
  }
};
