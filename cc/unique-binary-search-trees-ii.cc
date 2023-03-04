// http://leetcode.com/problems/unique-binary-search-trees-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<TreeNode *> generateTrees(int n) { return do_gen(1, n); }

private:
  vector<TreeNode *> do_gen(int from, int to) {
    if (from > to) {
      return {nullptr};
    }
    if (from == to) {
      return {new TreeNode(from)};
    }
    vector<TreeNode *> ret;

    for (int i = from; i <= to; i++) {
      auto lefts = do_gen(from, i - 1);
      auto rights = do_gen(i + 1, to);

      for (auto &left : lefts) {
        for (auto &right : rights) {
          TreeNode *cur = new TreeNode(i);
          cur->left = left;
          cur->right = right;
          ret.push_back(cur);
        }
      }
    }

    return ret;
  }
};

