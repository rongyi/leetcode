// http://leetcode.com/problems/tree-of-coprimes/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getCoprimes(vector<int> &nums, vector<vector<int>> &edges) {
    unordered_set<int> values(nums.begin(), nums.end());
    for (auto v1 : values) {
      for (auto v2 : values) {
        if (__gcd(v1, v2) == 1) {
          coprimes_[v1].push_back(v2);
        }
      }
    }
    // edges in matrix
    vector<vector<int>> es(nums.size());
    for (auto &e : edges) {
      es[e[0]].push_back(e[1]);
      es[e[1]].push_back(e[0]);
    }

    vector<int> ret(nums.size(), -1);
    dfs(nums, es, 0, 0, 0, ret);
    return ret;
  }

private:
  void dfs(vector<int> &nums, vector<vector<int>> &edges, int cur, int parent,
           int depth, vector<int> &ret) {
    int max_level = -1;
    // 找当前节点coprime的这些value对应的index
    for (auto &cur_cop : coprimes_[nums[cur]]) {
      auto &path = ancestors_[cur_cop];
      // 后面的总是最深的(离当前节点最近的祖先节点)
      if (!path.empty() && path.back().first > max_level) {
        max_level = path.back().first;
        ret[cur] = path.back().second;
      }
    }
    ancestors_[nums[cur]].push_back({depth, cur});
    for (auto child : edges[cur]) {
      if (child != parent) {
        dfs(nums, edges, child, cur, depth + 1, ret);
      }
    }
    ancestors_[nums[cur]].pop_back();
  }

private:
  // node value --> node values where gcd (key, v[i]) == 1
  unordered_map<int, vector<int>> coprimes_;
  // node value --> [{depth, node}]
  // value重复也没关系，总是用vector的最后一个，祖先最近的那个
  unordered_map<int, vector<pair<int, int>>> ancestors_;
};

int main() { cout << __gcd(3, 3) << endl; }
