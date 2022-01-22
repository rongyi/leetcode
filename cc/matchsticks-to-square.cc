// http://leetcode.com/problems/matchsticks-to-square/description/
#include "xxx.hpp"

class Solution {
public:
  bool makesquare(vector<int> &nums) {
    // 太短
    const int n = nums.size();
    if (n < 4) {
      return false;
    }

    // 如果总和不能分四份，也不行
    auto total = accumulate(nums.begin(), nums.end(), 0);
    if ((total % 4) != 0) {
      return false;
    }
    const int side = total / 4;
    vector<int> rets(4, 0);

    sort(nums.begin(), nums.end(), greater<int>());

    return dfs(nums, rets, 0, side);
  }

private:
  bool dfs(vector<int> &nums, vector<int> &rets, int index, int target) {
    if (index == nums.size()) {
      if (rets[0] == target && rets[1] == target && rets[2] == target) {
        return true;
      }
      return false;
    }
    for (int i = 0; i < 4; ++i) {
      if (rets[i] + nums[index] > target) {
        continue;
      }
      rets[i] += nums[index];
      if (dfs(nums, rets, index + 1, target)) {
        return true;
      }
      rets[i] -= nums[index];
    }
    return false;
  }
  // 没看清题目，先写这种方案了
  bool makesquarePartial(vector<int> &nums) {
    const int n = nums.size();
    if (n < 4) {
      return false;
    }
    vector<int> occurs;
    unordered_map<int, int> counts;

    for (auto stick : nums) {
      counts[stick]++;
      // 仅用这一种规格的火柴就可以了
      if (counts[stick] >= 4) {
        return true;
      }
    }
    for (auto kv : counts) {
      occurs.push_back(kv.first);
    }
    // 能用短的拼接，但是不能用长的折断，所以我们从最长的开始找
    sort(occurs.begin(), occurs.end(), greater<int>());

    for (int i = 0; i < occurs.size(); ++i) {
      auto stick_len = occurs[i];
      auto stick_count = counts[stick_len];
      for (int j = i + 1; j < occurs.size(); ++j) {
        // 能够用短的凑成长的
        if (stick_len % occurs[j] == 0 &&
            (stick_count + counts[occurs[j]] / stick_len >= 4)) {
          return true;
        }
      }
    }
    return false;
  }
};
int main() {
  Solution so;
  vector<int> input{
      1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
      1, 1, 1, 1, 1, 1, 6, 5, 6, 5, 7, 4, 8, 3,
  };
  auto ret = so.makesquare(input);
  cout << ret << endl;
}
