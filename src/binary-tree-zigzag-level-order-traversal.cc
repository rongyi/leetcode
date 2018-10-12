// http://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/description/
#include "one.h"

class Solution {
public:
  vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> ret;
    if (!root) {
      return ret;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool is_insert = false;
    while (!q.empty()) {
      vector<int> cur;
      auto len = q.size();
      // for every level
      for (int i = 0; i < len; ++i) {
        // zigzag action
        if (is_insert) {
          cur.insert(cur.begin(), q.front()->val);
        } else {
          cur.push_back(q.front()->val);
        }

        if (q.front()->left) {
          q.push(q.front()->left);
        }
        if (q.front()->right) {
          q.push(q.front()->right);
        }
        // consume this node
        q.pop();
      }
      is_insert = !is_insert;
      ret.push_back(cur);
    }

    return ret;
  }
};
