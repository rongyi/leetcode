// http://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
#include "xxx.hpp"

class Solution {
public:
  bool canPartitionKSubsets(vector<int> &nums, int k) {
    int total = accumulate(nums.begin(), nums.end(), 0);
    // 除不尽啊
    if (total % k != 0) {
      return false;
    }
    // 每一块的和为：
    int each_sum = total / k;
    // 一块都已经超过这个值了，所以没得选
    if (*max_element(nums.begin(), nums.end()) > each_sum) {
      return false;
    }
    vector<int> visited(nums.size(), 0);
    return dfs(nums, visited, k, each_sum, 0, 0);
  }
  bool dfs(vector<int> &nums, vector<int> &visited, int k, int target,
           int start_index, int cur_sum) {
    // 能够走到1，那么剩下的就不看了，最后一组肯定也满足，因为已经算过和了
    if (k == 1) {
      return true;
    }
    if (cur_sum == target) {
      return dfs(nums, visited, k - 1, target, 0, 0);
    }
    for (int i = start_index; i < nums.size(); i++) {
      if (!visited[i]) {
        // 用了这个数字
        visited[i] = 1;
        if (dfs(nums, visited, k, target, i + 1, cur_sum + nums[i])) {
          return true;
        }
        // 不用这个数字
        visited[i] = 0;
      }
    }
    return false;
  }
};

int main() {
  Solution so;
}
