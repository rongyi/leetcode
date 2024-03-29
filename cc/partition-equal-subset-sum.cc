// http://leetcode.com/problems/partition-equal-subset-sum/description/
#include "xxx.hpp"

class Solution {
public:
  bool canPartition(vector<int> &nums) {
    int half = accumulate(nums.begin(), nums.end(), 0);
    // must be even
    if (half & 1) {
      return false;
    }
    half >>= 1;
    if (*max_element(nums.begin(), nums.end()) > half) {
      return false;
    }

    vector<bool> dp(half + 1, false);
    dp[0] = true;
    for (auto n : nums) {
      for (int i = half; i >= n; --i) {
        // 意思就是如果和可以到某个节点，那么和就可以到这个节点的值加当前节点
        // 当前节点是n，所以i - n可达，那么到n就可达了
        if (dp[i - n]) {
          dp[i] = true;
        }
        if (dp[half]) {
          return true;
        }
      }
    }
    return false;
  }
  // 方便理解，过不了大数集
  bool canPartitionTLE(vector<int> &nums) {
    int half = accumulate(nums.begin(), nums.end(), 0);
    // must be even
    if (half & 1) {
      return false;
    }
    half >>= 1;
    if (*max_element(nums.begin(), nums.end()) > half) {
      return false;
    }

    return recur(nums, nums.size(), half);
  }

private:
  bool recur(vector<int> &nums, int n, int sum) {
    if (sum == 0) {
      return true;
    }
    if (n == 0) {
      return false;
    }

    // 对于每个数可取可不取
    return recur(nums, n - 1, sum) /*不取这个数*/ ||
           recur(nums, n - 1, sum - nums[n - 1]); /*取这个数*/
  }
};
