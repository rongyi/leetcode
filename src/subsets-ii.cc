// http://leetcode.com/problems/subsets-ii/description/
#include "one.h"

class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(nums, 0, cur, ret);
    return ret;
  }
public:
  void dfs(vector<int> &nums, int index, vector<int> &cur, vector<vector<int>> &ret) {
    ret.push_back(cur);
    for (int i = index; i < nums.size(); ++i) {
      if (i != index && nums[i] == nums[i - 1]) {
        continue;
      }
      cur.push_back(nums[i]);
      dfs(nums, i + 1, cur, ret);
      cur.pop_back();
    }
  }
};

int main() {
  Solution so;
  vector<int> input{1, 2, 2};
  auto ret = so.subsetsWithDup(input);
  for (auto &v: ret) {
    for (auto i :v) {
      cout << i << " ";
    }
    cout << endl;
  }
}
