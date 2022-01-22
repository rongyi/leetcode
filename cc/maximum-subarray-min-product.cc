// http://leetcode.com/problems/maximum-subarray-min-product/description/
#include "xxx.hpp"

class Solution {
public:
  int maxSumMinProduct(vector<int> &nums) {
    int sz = nums.size();
    vector<int> left(sz, 0);
    vector<int> right(sz, 0);
    // prefix sum
    vector<long long> dp(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      dp[i + 1] = dp[i] + nums[i];
    }

    vector<pair<int, int>> stk;
    // left range which all >= cur
    // set me as the lowest num[i] and expand the left and
    // see how far we can go
    for (int i = 0; i < sz; ++i) {
      int cur_count = 1;
      while (!stk.empty() && (stk.back().first > nums[i])) {
        cur_count += stk.back().second;
        // 意思就是说现在遇到一个比自己小的那么左边的包括我自己都可以和这个小的
        // 拼在一起用
        stk.pop_back();
      }
      stk.push_back({nums[i], cur_count});
      left[i] = cur_count;
    }

    // same , expand to right to see how far we can go
    stk.clear();
    for (int i = sz - 1; i >= 0; --i) {
      int cur_count = 1;
      while (!stk.empty() && (stk.back().first >= nums[i])) {
        cur_count += stk.back().second;
        stk.pop_back();
      }
      // 再push进来的意思就是挡着的意思
      stk.push_back({nums[i], cur_count});
      right[i] = cur_count;
    }
    long long ret = 0;
    for (int i = 0; i < sz; ++i) {
      int l = i - left[i] + 1;
      int r = i + right[i] - 1;

      long long cur_sum = dp[r + 1] - dp[l];
      ret = max(ret, nums[i] * cur_sum);
    }

    return ret % (long long)(1e9 + 7);
  }
};

int main() {
  Solution so;
  vector<int> input{3, 2, 2, 2, 2};
  so.maxSumMinProduct(input);
}
