// http://leetcode.com/problems/number-of-sets-of-k-non-overlapping-line-segments/description/
#include "xxx.hpp"

class Solution {
public:
  int numberOfSets(int n, int k) {
    mod_ = pow(10, 9) + 7;
    n_ = n;
    // 每一个点都有两种选择： 可选，可不选
    // 1. 但还要看前面有没有一条线划过来
    // dp[i][j][k]
    // 1. k is true ==> 从i这里可以开条新线，总条目数为j
    // 2. k is false ==>
    dp_ = vector<vector<vector<int>>>(
        n, vector<vector<int>>(n, vector<int>(2, -1)));

    return dfs(0, k, 1);
  }

private:
  int dfs(int i, int k, int canStart) {
    if (k == 0) {
      return 1;
    }
    if (i == n_) {
      return 0;
    }
    long long ret = dp_[i][k][canStart];
    if (ret != -1) {
      return ret;
    }

    // 不取这个点，要么是已经开始了(canStart=0)，那么就顺着划过去, 下一个点开始canStart仍然为0
    // 要么就是没开始(canStart=1)，那么跳过这个点，下一个点canStart为1
    // 总结起来就是跟参数一样
    ret = dfs(i + 1, k, canStart);

    if (canStart) {
      // 如果能开始，那么就从这个点开始被，下一个点canStart为0
      ret += dfs(i + 1, k, 0);
    } else {
      // 如果不能开始，那么这一根就到这里结束，从i开始一个全新的线段
      ret += dfs(i, k - 1, 1);
    }

    ret %= mod_;
    dp_[i][k][canStart] = ret;

    return ret;
  }

private:
  int mod_;
  int n_;
  vector<vector<vector<int>>> dp_;
};
