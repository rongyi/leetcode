// http://leetcode.com/problems/ways-to-make-a-fair-array/description/
#include "xxx.h"

class Solution {
public:
  int waysToMakeFair(vector<int> &nums) {
    int sum_odd = 0;
    int sum_even = 0;
    const int n = nums.size();
    for (int i = 0; i < n; ++i) {
      if (i & 1) {
        sum_odd += nums[i];
      } else {
        sum_even += nums[i];
      }
    }
    int cur_sum_odd = 0;
    int cur_sum_even = 0;
    int ret = 0;
    for (int i = 0; i < n; ++i) {
      bool is_cur_odd = (i & 1);
      // 到目前的和，是为了算后面的和
      if (is_cur_odd) {
        cur_sum_odd += nums[i];
      } else {
        cur_sum_even += nums[i];
      }
      // 后面的
      int after_sum_odd = sum_odd - cur_sum_odd;
      int after_sum_even = sum_even - cur_sum_even;

      // 删除掉的是个奇数
      if (is_cur_odd) {
        cur_sum_odd -= nums[i];
      } else {
        cur_sum_even -= nums[i];
      }

      // 后面的变奇偶性
      cur_sum_odd += after_sum_even;
      cur_sum_even += after_sum_odd;
      if (cur_sum_odd == cur_sum_even) {
        ret++;
      }

      // 不行，补回去
      if (is_cur_odd) {
        cur_sum_odd += nums[i];
      } else {
        cur_sum_even += nums[i];
      }

      cur_sum_odd -= after_sum_even;
      cur_sum_even -= after_sum_odd;
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{2, 1, 6, 4};
  auto ret = so.waysToMakeFair(input);
  cout << ret << endl;
}
