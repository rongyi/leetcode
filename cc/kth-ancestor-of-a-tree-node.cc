// http://leetcode.com/problems/kth-ancestor-of-a-tree-node/description/
#include "xxx.h"

class TreeAncestor {
public:
  // ref: https://leetcode.com/problems/kth-ancestor-of-a-tree-node/discuss/686291/C%2B%2B-Jump-Array
  TreeAncestor(int n, vector<int> &parent) {
    vector<vector<int>> tree(n);
    jumps_ = vector<vector<int>>(n);
    levels_ = vector<int>(n);
    for (auto i = 1; i < n; ++i) {
      // 从根到孩子的方向记录
      tree[parent[i]].push_back(i);
    }
    vector<int> path;
    traverse(path, tree, 0, 0);
  }

  int getKthAncestor(int node, int k) {
    if (k == 0) {
      return node;
    }
    if (levels_[node] < k) {
      return -1;
    }
    auto p = 1;
    auto pos = 0;
    // 跳到最接近的地方去
    while ((p << 1) <= k) {
      p <<= 1;
      ++pos;
    }

    // 剩下来递归
    return getKthAncestor(jumps_[node][pos], k - p);
  }

private:
  void traverse(vector<int> &path, vector<vector<int>> &tree, int cur_node,
                int curl_level) {
    levels_[cur_node] = curl_level;
    // 总是存1 2 4 8...这些位置的父节点
    for (int p = 1; p <= path.size(); p <<= 1) {
      jumps_[cur_node].push_back(path[path.size() - p]);
    }
    path.push_back(cur_node);
    for (auto ch : tree[cur_node]) {
      traverse(path, tree, ch, curl_level + 1);
    }
    path.pop_back();
  }

private:
  vector<int> levels_;
  vector<vector<int>> jumps_;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */

int main() {
  vector<int> input{-1, 0, 0, 1, 1, 2, 2};
  TreeAncestor ta = TreeAncestor(7, input);
  auto n = ta.getKthAncestor(3, 1);
  cout << n << endl;

  // int k = 4;
  // auto p = 1;
  // auto pos = 0;
  // while ((p << 1) <= k) {
  //   p <<= 1;
  //   ++pos;
  // }
  // cout << pos << endl;
}
