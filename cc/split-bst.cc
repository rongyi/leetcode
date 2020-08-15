// http://www.lintcode.com/zh-cn/problem/split-bst
#include "xxx.h"
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
  vector<TreeNode *> splitBST(TreeNode *root, int V) {
    if (!root) {
      return vector<TreeNode *>{nullptr, nullptr};
    }
    if (root->val == V) {
      auto right = root->right;
      root->right = nullptr;
      return vector<TreeNode *>{root, right}; // 返回结果严格左子树右子树
    } else if (root->val < V) {               // to right subtree
      auto ret = splitBST(root->right, V);
      auto left = ret[0];
      auto right = ret[1];
      root->right = left;
      return vector<TreeNode *>{root, right};
    } else { // to left subtree
      auto ret = splitBST(root->left, V);
      auto left = ret[0];
      auto right = ret[1];
      root->left = right;
      return vector<TreeNode *>{left, root};
    }
  }
};

int main() {
  TreeNode n1(1), n2(2), n3(3), n4(4), n5(5), n6(6), n7(7);
  n4.left = &n2;
  n4.right = &n6;
  n2.left = &n1;
  n2.right = &n3;
  n6.left = &n5;
  n6.right = &n7;

  Solution so;
  auto ret = so.splitBST(&n4, 3);
  if (ret[0]) {
    cout << ret[0]->val << endl;
  }
  if (ret[1]) {
    cout << ret[1]->val << endl;
  }
}
