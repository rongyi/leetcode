// http://leetcode.com/problems/minimum-incompatibility/description/
#include "xxx.h"

class Solution {
public:
  int minimumIncompatibility(vector<int> &nums, int k) {
    const int INF = 1e9;
    const int n = nums.size();
    const int grou_size = n / k;

    // 为了方便算后面的区间最大值最小值
    sort(nums.begin(), nums.end());

    // nums中的每一个元素可取可不取，总共
    // 2^^n个组合，把这里面所有的组合区间的最大值最小值差算出来
    vector<int> range(1 << n, INF);
    // mask表示的就是nums中某一index上的num取了没有
    for (int cur_mask = 1; cur_mask < (1 << n); ++cur_mask) {
      int cur_min = -1;
      int cur_max = -1;
      bool dup = false;

      for (int i = 0; i < n && !dup; ++i) {
        // 表示nums[i]在当前mask组合上被取到了
        if (cur_mask & (1 << i)) {
          if (cur_min == -1) {
            cur_min = nums[i];
          }
          if (cur_max == nums[i]) {
            dup = true;
          }
          cur_max = nums[i];
        }
      }
      if (!dup) {
        range[cur_mask] = cur_max - cur_min;
      }
    }
    vector<int> dp(1 << n, INF);
    dp[0] = 0;

    for (int cur_mask = 1; cur_mask < (1 << n); ++cur_mask) {
      for (int submask = cur_mask; submask;
           submask = (submask - 1) & cur_mask) {
        // 自己实现超时 :(
        if (__builtin_popcount(submask) == grou_size) {
          dp[cur_mask] =
            // 区间是从小到大展开，所以后面的 dp[cur_mask ^ submask] 一定是已经算好的最小值
              min(dp[cur_mask], range[submask] + dp[cur_mask ^ submask]);
        }
      }
    }

    if (dp.back() >= INF) {
      return -1;
    }
    return dp.back();
  }

public:
  int bitcount(int n) {
    int ret = 0;
    while (n) {
      ++ret;
      n &= (n - 1);
    }

    return ret;
  }
};

int main() {
  Solution so;
  cout << so.bitcount(15) << endl;
}
