// https://leetcode.com/problems/max-sum-of-a-pair-with-equal-sum-of-digits/
#include "xxx.hpp"

class Solution {
public:
  int maximumSum(vector<int> &nums) {
    int ret = -1;
    map<int, priority_queue<int>> group;
    auto get_digit_sum = [](int num) -> int {
      int ret = 0;

      while (num) {
        ret += (num % 10);
        num /= 10;
      }

      return ret;
    };
    for (auto num : nums) {
      group[get_digit_sum(num)].push(num);
    }

    for (auto &kv : group) {
      if (kv.second.size() > 1) {
        auto n1 = kv.second.top();
        kv.second.pop();
        auto n2 = kv.second.top();
        ret = max(ret, n1 + n2);
      }
    }
    return ret;
  }
};
