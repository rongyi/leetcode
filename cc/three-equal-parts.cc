// http://leetcode.com/problems/three-equal-parts/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> threeEqualParts(vector<int> &A) {
    vector<int> dp;
    for (int i = 0; i < A.size(); i++) {
      if (A[i]) {
        dp.push_back(i);
      }
    }

    // 1的个数不能均分
    if (dp.size() % 3) {
      return {-1, -1};
    }
    // 没有1，随便分
    if (dp.empty()) {
      return {0, 2};
    }

    // 1的分布规律应该一致
    int l1 = 0;
    int l2 = dp.size() / 3;
    int l3 = l2 * 2;

    for (int i = 1; i < l2; i++) {
      // 1与1之间的gap应该要一样的
      int diff = dp[i] - dp[i - 1];
      // 不满足
      if (dp[l2 + i] - dp[l2 + i - 1] != diff ||
          dp[l3 + i] - dp[l3 + i - 1] != diff) {
        return {-1, -1};
      }
    }
    // 后面的0个数也要一样，前面可以不一样
    // 算0，这个厉害
    // 如果最后一位是1的话那么这个tail0是1，所以
    // 这里大家都没有减一
    int tail0 = A.size() - dp.back();
    // 以l3举例
    // l3是第三部分的开始的第一个1， l3 - 1是第二部分的最后一个1，之间的gap就是中间有多少个0 - 1
    // 而对标的tail0也没有减一所以大家都这么算了
    // 另外为什么是小于，因为多了可以切，少了补不了啊
    if (dp[l3] - dp[l3 - 1] < tail0 || dp[l2] - dp[l2 - 1] < tail0) {
      return {-1, -1};
    }

    return {dp[l2 - 1] + tail0 - 1, dp[l3 - 1] + tail0};
  }
};
