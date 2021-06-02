// http://leetcode.com/problems/average-waiting-time/description/
#include "xxx.h"

class Solution {
public:
  double averageWaitingTime(vector<vector<int>> &customers) {
    int n = customers.size();
    int chef_finished_at = customers[0][0];
    double total_wait = 0;
    for (int i = 0; i < n; ++i) {
      int cur_entry = customers[i][0];
      chef_finished_at += customers[i][1];

      total_wait += (chef_finished_at - cur_entry);

      // 后面来的客人厨子已经忙完了，把时间提到客人来的时间
      if (i < n - 1 && customers[i + 1][0] > chef_finished_at) {
        chef_finished_at = customers[i + 1][0];
      }
    }
    return total_wait / n;
  }
};

int main() {
  Solution so;
  vector<vector<int>> input{{1, 2}, {2, 5}, {4, 3}};
  so.averageWaitingTime(input);
}
