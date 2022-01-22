// http://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() : count_{} {}
  int pseudoPalindromicPaths(TreeNode *root) {

    int ret = 0;
    recur(root, ret);

    return ret;
  }

private:
  void recur(TreeNode *cur_node, int &ret) {
    if (!cur_node) {
      return;
    }
    ++count_[cur_node->val];

    // a leaf node
    if (!cur_node->left && !cur_node->right) {
      if (isp()) {
        ++ret;
      }
    }

    recur(cur_node->left, ret);
    recur(cur_node->right, ret);

    --count_[cur_node->val];
  }
  bool isp() {
    bool odd_occr = false;
    for (int i = 1; i < 10; ++i) {
      if (count_[i] & 1) {
        if (odd_occr) {
          return false;
        }
        odd_occr = true;
      }
    }

    return true;
  }

private:
  int count_[10];
};

int main() {}
