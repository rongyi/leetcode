// http://leetcode.com/problems/make-array-strictly-increasing/description/
#include "xxx.h"

class Solution {
public:
  int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2) {
    const int m = arr1.size();
    const int n = arr2.size();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    sort(arr2.begin(), arr2.end());

    auto ret = dfs(dp, arr1, arr2, 0, 0, numeric_limits<int>::min());

    return ret > arr2.size() ? -1 : ret - 1;
  }

private:
  int dfs(vector<vector<int>> &dp, vector<int> &a1, vector<int> &a2, int i1,
          int i2, int prev) {
    if (i1 >= a1.size()) {
      return 1;
    }
    i2 = upper_bound(a2.begin() + i2, a2.end(), prev) - a2.begin();
    if (dp[i1][i2]) {
      return dp[i1][i2];
    }
    // 又两个分支，一个是和a2里面的一个数更换, prev ==> a2[i2]
    // 更新i2是由上面upper_bound做e掉了，所以这里和下面的i2都没有更新
    auto r1 = i2 < a2.size() ? 1 + dfs(dp, a1, a2, i1 + 1, i2, a2[i2])
                             : a2.size() + 1;
    // 另一个就是不更换，prev就是a1[i1]
    auto r2 =
        prev < a1[i1] ? dfs(dp, a1, a2, i1 + 1, i2, a1[i1]) : a2.size() + 1;
    return dp[i1][i2] = min(r1, r2);
  }
};
