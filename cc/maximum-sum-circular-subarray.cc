// http://leetcode.com/problems/maximum-sum-circular-subarray/description/
#include "xxx.h"

class Solution {
public:
  int maxSubarraySumCircular(vector<int> &A) {
    int sum = accumulate(A.begin(), A.end(), 0);
    int sub1_sum = maxSubSum(A.begin(), A.end());
    // 这里用到的一个思路是循环的子数组的和
    // a b c d e f
    // e.g 算e f a的和的话就是拿sum - (b + c + d)
    for (auto &i : A) {
      i *= -1;
    }
    int sub2_sum = sum + maxSubSum(A.begin() + 1, A.end() - 1);

    return max(sub1_sum, sub2_sum);
  }
private:
  int maxSubSum(vector<int>::iterator begin, vector<int>::iterator end) {
    int ret = numeric_limits<int>::min();
    int cur_sum = 0;
    for (auto it = begin; it != end; it++) {
      cur_sum += *it;
      ret = max(ret, cur_sum);
      if (cur_sum < 0) {
        // 老子从头开始一个子数组，不要前面那些货了
        cur_sum = 0;
      }
    }
    return ret;
  }
};
