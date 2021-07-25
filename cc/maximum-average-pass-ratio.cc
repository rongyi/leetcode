// http://leetcode.com/problems/maximum-average-pass-ratio/description/
#include "xxx.h"

class Solution {
public:
  /*
  double maxAverageRatioWrong(vector<vector<int>> &classes, int extraStudents) {
    const int n = classes.size();
    double total_ratio = 0.0;
    double max_delte = 0.0;
    for (auto &t : classes) {
      double cur_ratio = (double)t[0] / t[1];
      total_ratio += cur_ratio;
      // 否则extra加上面不产生delta
      // 不是一起分的，而是一个一个分的，所以错在这里
      if (t[0] < t[1]) {
        double new_ratio =
            ((double)t[0] + extraStudents) / (t[1] + extraStudents);
        if (new_ratio > cur_ratio) {
          max_delte = max(max_delte, (new_ratio - cur_ratio));
        }
      }
    }

    return (total_ratio + max_delte) / n;
  }
  */

  // 要一个一个的添加
  double maxAverageRatio(vector<vector<int>> &classes, int extraStudents) {
    const int n = classes.size();
    // put one studutent in cur to get the profit
    auto get_profit = [&](double pass, double total) {
      return (pass + 1) / (total + 1) - pass / total;
    };
    double total_ratio = 0.0;
    // 按照profit排序，加在最有价值的班级，即delta最大
    priority_queue<pair<double, array<int, 2>>> pq;
    for (auto &t : classes) {
      pq.push({get_profit(t[0], t[1]), {t[0], t[1]}});
      // 没有加extra的情况
      total_ratio += (double)t[0] / t[1];
    }
    while (extraStudents) {
      auto [added_profit, t] = pq.top();
      pq.pop();
      total_ratio += added_profit;
      pq.push({get_profit(t[0] + 1, t[1] + 1), {t[0] + 1, t[1] + 1}});

      extraStudents--;
    }

    return total_ratio / n;
  }
};
