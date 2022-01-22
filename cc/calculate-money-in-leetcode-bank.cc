// http://leetcode.com/problems/calculate-money-in-leetcode-bank/description/
#include "xxx.hpp"

class Solution {
public:
  int totalMoney(int n) {
    const int first_group_sum = 28;
    const int group_delte = 7;

    int group = n / 7;
    int last_len = n % 7;

    int ret = 0;
    // 等差数列
    if (group > 0) {
      ret += group *
             (first_group_sum + first_group_sum + (group - 1) * group_delte) /
             2;
    }

    // 后面懒得用公式了
    for (int i = 0, start = group + 1; i < last_len; ++i, start++) {
      ret += start;
    }

    return ret;
  }
};

int main() {
  Solution so;

  cout << so.totalMoney(20) << endl;
}
