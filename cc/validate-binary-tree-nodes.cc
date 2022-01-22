// http://leetcode.com/problems/validate-binary-tree-nodes/description/
#include "xxx.hpp"

class Solution {
public:
  // union find
  // 1. node nodes should have 2 parents
  // 2. exactly one node have no parent
  bool validateBinaryTreeNodes(int n, vector<int> &left, vector<int> &right) {
    vector<int> pars(n, 0);
    vector<int> ds(n, -1);
    for (int i = 0; i < n; ++i) {
      if (!process_link(pars, ds, i, left[i]) ||
          !process_link(pars, ds, i, right[i])) {
        return false;
      }
    }
    auto zero_parent = count_if(pars.begin(), pars.end(),
                                [](int i) -> bool { return i == 0; });
    auto zero_group =
        count_if(ds.begin(), ds.end(), [](int i) -> bool { return i < 0; });

    return zero_parent == 1 && zero_group == 1;
  }

private:
  int find(vector<int> &ds, int idx) {
    if (ds[idx] < 0) {
      return idx;
    }
    ds[idx] = find(ds, ds[idx]);
    return ds[idx];
  }
  bool process_link(vector<int> &pars, vector<int> &ds, int parent, int child) {
    if (child == -1) {
      return true;
    }
    auto p = find(ds, parent);
    auto c = find(ds, child);
    // 归类到parent上
    if (p != c) {
      // ds[p] += ds[c];
      ds[c] = p;
    }
    ++pars[child];

    return pars[child] < 2;
  }

  bool validateBinaryTreeNodesTLE(int n, vector<int> &leftChild,
                                  vector<int> &rightChild) {

    for (int i = 0; i < n; i++) {
      // the first index 0 node
      int node_count = 1;
      unordered_set<int> visited;
      visited.insert(i);
      auto cret =
          construct_binary_tree(i, node_count, visited, leftChild, rightChild);
      if (cret > 0 && cret == n) {
        return true;
      }
    }
    return false;
  }
  int construct_binary_tree(int cur_index, int &node_count,
                            unordered_set<int> &visited, vector<int> &left,
                            vector<int> &right) {
    auto l = left[cur_index];
    auto r = right[cur_index];
    // finish
    if (l == -1 && r == -1) {
      return node_count;
    }
    if (l != -1) {
      if (visited.find(l) != visited.end()) {
        return -1;
      }

      node_count++;
      visited.insert(l);
      auto ret = construct_binary_tree(l, node_count, visited, left, right);
      if (ret == -1) {
        return -1;
      }
    }
    if (r != -1) {
      if (visited.find(r) != visited.end()) {
        return -1;
      }
      node_count++;
      visited.insert(r);
      auto ret = construct_binary_tree(r, node_count, visited, left, right);
      if (ret == -1) {
        return -1;
      }
    }

    return node_count;
  }
};

int main() {
  Solution so;
  vector<int> left{1, -1, 3, -1};
  vector<int> right{2, 3, -1, -1};

  auto ret = so.validateBinaryTreeNodes(4, left, right);
  cout << ret << endl;
}
