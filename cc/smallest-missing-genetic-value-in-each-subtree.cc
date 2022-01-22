// https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/
#include "xxx.hpp"

class Solution {
public:
  vector<int> smallestMissingValueSubtree(vector<int> &parents,
                                          vector<int> &nums) {
    visited_ = vector<bool>(1e5 + 2, false);
    int sz = parents.size();
    vector<vector<int>> child(sz);
    for (int i = 1; i < sz; ++i) {
      child[parents[i]].push_back(i);
    }
    vector<int> ret(sz, 1);
    // find the num 1 position and traverse to root
    // all subtree other than this path, its value is 1
    int pos = find(nums.begin(), nums.end(), 1) - nums.begin();
    // gen value start from 1
    int min = 1;
    // see this visual
    // https://leetcode.com/problems/smallest-missing-genetic-value-in-each-subtree/discuss/1459111/Visualization-with-code-or-C%2B%2B
    // to parent -> visit its all child(mark its child)
    for (; pos < sz && pos != -1; pos = parents[pos]) {
      dfs(pos, child, nums);
      while (visited_[min]) {
        ++min;
      }
      ret[pos] = min;
    }

    return ret;
  }

private:
  void dfs(int pos, vector<vector<int>> &child, vector<int> &nums) {
    if (visited_[nums[pos]]) {
      return;
    }
    visited_[nums[pos]] = true;
    for (auto &c : child[pos]) {
      dfs(c, child, nums);
    }
  }

private:
  vector<bool> visited_;
};
