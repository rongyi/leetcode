// https://leetcode.com/problems/create-components-with-same-value/
#include "xxx.hpp"

class Solution {
public:
  int componentValue(vector<int> &nums, vector<vector<int>> &edges) {
    int sum = accumulate(nums.begin(), nums.end(), 0);

    int sz = nums.size();
    vector<vector<int>> neibs(sz);
    for (auto &e : edges) {
      neibs[e[0]].push_back(e[1]);
      neibs[e[1]].push_back(e[0]);
    }

    for (int i = sz; i >= 1; --i) {
      // can not form group i, there are some left values
      if (sum % i) {
        continue;
      }
      vector<int> visited(sz, 0);
      if (dfs(nums, neibs, 0, visited, sum / i) == 0) {
        return i - 1;
      }
    }

    return 0;
  }

private:
  int dfs(vector<int> &nums, vector<vector<int>> &neibs, int cur,
          vector<int> &visited, int target) {
    visited[cur] = nums[cur];
    for (auto &next : neibs[cur]) {
      // visited value, pass
      if (visited[next]) {
        continue;
      }
      visited[cur] += dfs(nums, neibs, next, visited, target);
      // prune
      if (visited[cur] > target) {
        return 1e7;
      }
    }
    // cut from here, act like this subtree(which root is cur) is detached!
    if (visited[cur] == target) {
      return 0;
    }

    return visited[cur];
  }
};
