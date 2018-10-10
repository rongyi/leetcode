// http://leetcode.com/problems/unique-binary-search-trees-ii/description/
#include "one.h"

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) {
    if (n == 0) {
      return vector<TreeNode *>{};
    }
    // 层序遍历输出
    return do_gen(1, n);
  }

private:
  vector<TreeNode *> do_gen(int ld, int rd) {
    vector<TreeNode *> ret;
    if (ld == rd) {
      TreeNode *tmp = new TreeNode(ld);
      ret.push_back(tmp);
      return ret;
    }
    if (ld > rd) {
      ret.push_back(nullptr);
      return ret;
    }

    // 和上一题类似，左子树分配0到n - 1 ,右子树分配 0 到 n - 1
    for (int i = ld; i <= rd; ++i) {
      vector<TreeNode *> left = do_gen(ld, i - 1);
      vector<TreeNode *> right = do_gen(i + 1, rd);

      for (auto lx : left) {
        for (auto rx : right) {
          TreeNode *tmp = new TreeNode(i);
          tmp->left = lx;
          tmp->right = rx;
          ret.push_back(tmp);
        }
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  so.generateTrees(1);
}
