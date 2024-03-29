// http://leetcode.com/problems/subtree-of-another-tree/description/
#include "xxx.hpp"

class Solution {
public:
  bool isSubtree(TreeNode *s, TreeNode *t) {
    return recur(s, t, true);
  }

private:
  // start_from_root: doest this t node is a root node or original t
  // if no, when we meet values not equal we return false imediately
  bool recur(TreeNode *s, TreeNode *t, bool start_from_root) {
    bool hass = !!s;
    bool hast = !!t;
    if (hass ^ hast) {
      return false;
    }
    // either s == t == nullptr
    // or s != nullptr && t != nullptr
    if (!s) {
      return true;
    }
    if (s->val == t->val) {
      if (recur(s->left, t->left, false) && recur(s->right, t->right, false)) {
        return true;
      }
    } else if (!start_from_root) {
      return false;
    }
    return recur(s->left, t, true) || recur(s->right, t, true);
  }
};
