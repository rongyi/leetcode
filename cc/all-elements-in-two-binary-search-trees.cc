// http://leetcode.com/problems/all-elements-in-two-binary-search-trees/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
    vector<int> t1;
    vector<int> t2;
    collect(root1, t1);
    collect(root2, t2);

    t1.insert(t1.end(), t2.begin(), t2.end());
    sort(t1.begin(), t1.end());

    return t1;
  }

private:
  void collect(TreeNode *cur, vector<int> &ret) {
    if (!cur) {
      return;
    }
    ret.push_back(cur->val);
    collect(cur->left, ret);
    collect(cur->right, ret);
  }
};
