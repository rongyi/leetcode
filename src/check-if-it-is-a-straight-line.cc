// http://leetcode.com/problems/check-if-it-is-a-straight-line/description/
#include "xxx.h"

class Solution {
public:
  bool checkStraightLine(vector<vector<int>> &coordinates) {
    unordered_set<double> uniq;
    for (int i = 0; i < coordinates.size(); ++i) {
      for (int j = i + 1; j < coordinates.size(); ++j) {
        auto pa = coordinates[i];
        auto pb = coordinates[j];

        if (pa[0] == pb[0]) {
          uniq.insert(numeric_limits<double>::max());
          if (uniq.size() > 1) {
            return false;
          }
        }
        double slope =
            ((double)pa[1] - (double)pb[1]) / ((double)pa[0] - (double)pb[0]);
        uniq.insert(slope);
        if (uniq.size() > 1) {
          return false;
        }
      }
    }

    return true;
  }
};
