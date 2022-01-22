// http://leetcode.com/problems/odd-even-jump/description/
#include "xxx.hpp"

class Solution {
public:
  // 往前跳
  // 1. 奇数次跳： 大于等于A[i]里面最小的
  // 2. 偶数次跳： 小于等于A[i]里面最大的
  // https://leetcode.com/problems/odd-even-jump/discuss/270684/C%2B%2B-with-map%3A%3Alowerupper_bound
  int oddEvenJumps(vector<int> &A) {
    using pii = pair<int, int>;
    // first==> 奇数跳， second==> 偶数跳
    vector<pii> dp(A.size());
    // 最后面一个都能跳过去
    dp.back() = {1, 1};

    map<int, int> index;
    int ret = 0;
    for (int i = A.size() - 1; i >= 0; i--) {
      // >= A[i]里面最小的
      auto odd_jump = index.lower_bound(A[i]);
      // 第一个大于A[i]的位置，那么再减一的这个值就是小于A[i]里面最大的
      auto even_jump = index.upper_bound(A[i]);
      if (odd_jump != index.end()) {
        // 那么从i这里开始的奇数跳能跳过去的话，
        // 决定权就在于下一跳偶数次跳的方式能不能过
        dp[i].first = dp[odd_jump->second].second;
      }
      if (even_jump != index.begin()) {
        --even_jump;
        // 和上面同理
        dp[i].second = dp[even_jump->second].first;
      }
      // starting x是奇数跳开头
      ret += dp[i].first;

      index[A[i]] = i;
    }

    return ret;
  }
};
