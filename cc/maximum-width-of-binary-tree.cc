// http://leetcode.com/problems/maximum-width-of-binary-tree/description/
#include "xxx.hpp"

class Solution {

public:
  int widthOfBinaryTree(TreeNode *root) {
    long ret = 0;
    queue<pair<TreeNode *, long>> q;
    q.push({root, 0});
    while (!q.empty()) {
      int len = q.size();
      long l = q.front().second;
      long r = 0;
      while (len) {
        pair<TreeNode *, long> cur = q.front();
        q.pop();
        if (cur.first->left) {
          q.push({cur.first->left, (cur.second - l) * 2});
        }
        if (cur.first->right) {
          q.push({cur.first->right, (cur.second - l) * 2 + 1});
        }
        r = max(r, cur.second);
        --len;
      }
      ret = max(ret, r - l + 1);
    }

    return ret;
  }

  int widthOfBinaryTreeOverFlow(TreeNode *root) {
    vector<int> lefts;
    long long max_width = 0;
    recur(root, 1, 1, lefts, max_width);

    return max_width;
  }

private:
  void recur(TreeNode *root, long long id, int level, vector<int> &lefts,
             long long &max_width) {
    if (!root) {
      return;
    }
    if (level > lefts.size()) {
      lefts.push_back(id);
    }
    max_width = max(max_width, id - lefts[level - 1] + 1);
    recur(root->left, 2 * id, level + 1, lefts, max_width);
    recur(root->right, 2 * id + 1, level + 1, lefts, max_width);
  }
};
int main() { Solution so; }
