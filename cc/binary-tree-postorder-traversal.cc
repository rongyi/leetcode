// http://leetcode.com/problems/binary-tree-postorder-traversal/description/
#include "xxx.h"

class Solution {
public:
  vector<int> postorderTraversal(TreeNode *root) {
    vector<int> ret;
    TreeNode *p;
    TreeNode *q;
    stack<TreeNode *> stk;
    p = root;

    do {
      while (p != nullptr) {
        stk.push(p);
        p = p->left;
      }
      q = nullptr;
      while (!stk.empty()) {
        p = stk.top();
        stk.pop();

        // 这里的判断要么就是右子树为空，或者是右子树已经被访问
        // 满足这个条件的要么是叶节点，要么是右子树一路往下光溜的情况
        if (p->right == q) {
          ret.push_back(p->val);
          q = p;
        } else {
          // 当前节点不能访问，需再次进栈,其实就是跳到下一个层次的往左下的链表的根节点
          stk.push(p);
          p = p->right;
          // 只前进一格，然后往左子树走到底==>do的最上面
          break;
        }
      }
    } while (!stk.empty());

    return ret;
  }
};
