// http://leetcode.com/problems/average-salary-excluding-the-minimum-and-maximum-salary/description/
#include "xxx.hpp"

class Solution {
public:
  double average(vector<int> &salary) {
    int min_slry = numeric_limits<int>::max();
    int max_slry = numeric_limits<int>::min();
    double sum = 0;
    for (auto &s : salary) {
      sum += s;
      min_slry = min(s, min_slry);
      max_slry = max(s, max_slry);
    }
    sum -= min_slry;
    sum -= max_slry;

    return sum / (salary.size() - 2);
  }
};
