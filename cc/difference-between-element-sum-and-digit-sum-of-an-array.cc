// https://leetcode.com/problems/difference-between-element-sum-and-digit-sum-of-an-array/
#include "xxx.hpp"

class Solution {
public:
  int differenceOfSum(vector<int> &nums) {
    int sum = 0;
    // too slow
    // auto numDgitSum = [](int n) {
    // int ret = 0;
    // while (n) {
    // ret += (n % 10);
    // n /= 10;
    //}
    // return ret;
    //};
    int dsum = 0;
    for (auto &num : nums) {
      sum += num;
      while (num) {
        dsum += (num % 10);
        num /= 10;
      }
    }

    return abs(dsum - sum);
  }
};
