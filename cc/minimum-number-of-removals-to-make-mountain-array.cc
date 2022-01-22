// http://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/description/
#include "xxx.hpp"

class Solution {
public:
  // 左边的最长递增subsequence (LIS)
  // left LIS
  // 在其中找最长的那个
  int minimumMountainRemovals(vector<int> &nums) {
    const int n = nums.size();
    int ret = numeric_limits<int>::max();
    vector<int> l;
    vector<int> r;
    vector<int> dp(n, 0);

    for (int i = 0; i < nums.size(); ++i) {
      auto it = lower_bound(begin(l), end(l), nums[i]);
      if (it == l.end()) {
        l.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
      dp[i] = l.size();
    }

    for (int i = n - 1; i > 0; --i) {
      auto it = lower_bound(begin(r), end(r), nums[i]);
      if (it == r.end()) {
        r.push_back(nums[i]);
      } else {
        *it = nums[i];
      }
      if (dp[i] > 1 && r.size() > 1) {
        // 全部moutain的长度是: (dp[i] + r.size() - 1)，中间那个元素重复了一次
        ret = min(ret, n - dp[i] - (int)r.size() + 1);
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{1, 3, 6, 2, 3, 5, 6};
  so.minimumMountainRemovals(input);
}
