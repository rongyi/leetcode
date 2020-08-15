// http://leetcode.com/problems/target-sum/description/
#include "xxx.h"

class Solution {
public:
  int findTargetSumWays(vector<int> &nums, int S) {
    count_ = 0;
    dfs(nums, S, 0);
    return count_;
  }

private:
  void dfs(vector<int> &nums, long long S, int pos) {
    if (pos == nums.size()) {
      count_ += !S;
      return;
    }

    dfs(nums, S - nums[pos], pos + 1);
    dfs(nums, S + nums[pos], pos + 1);
  }

private:
  int count_;
};

int main() {
  Solution so;
  vector<int> input{1, 1, 1, 1, 1};
  so.findTargetSumWays(input, 3);
}
