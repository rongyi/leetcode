// http://leetcode.com/problems/binary-tree-right-side-view/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> rightSideViewRaw(TreeNode *root) {
    vector<int> ret;
    auto level_list = levelOrderBottom(root);
    for (auto &level : level_list) {
      ret.push_back(level.back());
    }
    return ret;
  }

  // 直接精简过后的版本
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ret;
    if (!root) {
      return ret;
    }
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // 对于每一层就只保存最后面那位
      ret.push_back(q.back()->val);

      int cur_cnt = q.size();
      for (int i = 0; i < cur_cnt; ++i) {
        auto *cur = q.front();
        q.pop();
        if (cur->left) {
          q.push(cur->left);
        }
        if (cur->right) {
          q.push(cur->right);
        }
      }
    }

    return ret;
  }

private:
  // not work!! need level order
  void recursive(TreeNode *root, vector<int> &ret) {
    if (!root) {
      return;
    }
    ret.push_back(root->val);
    if (root->right) {
      recursive(root->right, ret);
    } else {
      recursive(root->left, ret);
    }
  }


  vector<vector<int>> levelOrderBottom(TreeNode *root) {
    vector<vector<int>> ret;
    if (!root) {
      return ret;
    }
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      vector<int> cur;
      int cur_cnt = q.size();
      for (int i = 0; i < cur_cnt; ++i) {
        cur.push_back(q.front()->val);
        if (q.front()->left) {
          q.push(q.front()->left);
        }
        if (q.front()->right) {
          q.push(q.front()->right);
        }
        q.pop();
      }
      ret.push_back(cur);
    }
    return ret;
  }
};
