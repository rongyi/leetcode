// http://leetcode.com/problems/increasing-subsequences/description/
#include "xxx.h"

class Solution {
public:
  vector<vector<int>> findSubsequences(vector<int> &nums) {
    vector<vector<int>> ret;
    vector<int> cur;
    dfs(nums, ret, cur, 0);
    return ret;
  }

private:
  void dfs(vector<int> &nums, vector<vector<int>> &ret, vector<int> &cur,
           int pos) {
    if (cur.size() > 1) {
      ret.push_back(cur);
    }
    unordered_set<int> uniq;
    for (int i = pos; i < nums.size(); ++i) {
      if ((cur.empty() || nums[i] >= cur.back()) && (uniq.find(nums[i]) == uniq.end())) {
        cur.push_back(nums[i]);
        dfs(nums, ret, cur, i + 1);
        cur.pop_back();
        uniq.insert(nums[i]);
      }
    }
  }
};

int main() {
  Solution so;
  vector<int> input{4, 6, 7, 7};
  auto ret = so.findSubsequences(input);
  for (auto vec : ret) {
    for (auto i : vec) {
      cout << i << " ";
    }
    cout << endl;
  }
}
