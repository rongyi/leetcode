// http://leetcode.com/problems/construct-string-from-binary-tree/description/
#include "xxx.h"

class Solution {
public:
  string tree2str(TreeNode *t) {
    if (!t) {
      return "";
    }
    stringstream ss;
    recur(t, ss);
    auto ret = ss.str();
    // omit the outer parenthesis
    ret.pop_back();

    return ret.substr(1);
  }
  void recur(TreeNode *t, stringstream &ss) {
    if (!t) {
      return;
    }
    ss << '(';
    ss << t->val;
    if (t->left) {
      recur(t->left, ss);
    } else if (t->right) {
      ss << "()";
    }
    recur(t->right, ss);
    ss << ')';
  }
};
