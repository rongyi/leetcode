// http://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
#include "xxx.h"

class Solution {
public:
  vector<int> countSmaller(vector<int> &nums) {
    const int n = nums.size();
    if (n == 0) {
      return vector<int>{};
    }
    if (n == 1) {
      return vector<int>{0};
    }

    vector<int> ret(n, 0);
    Node *root = nullptr;
    for (int i = n - 1; i >= 0; --i) {
      ret[i] = insert(&root, root, nums[i]);
    }

    return ret;
  }

private:
  struct Node {
    int val_;
    int less_than_;
    int count_;
    int space_;
    Node *left_;
    Node *right_;
    Node(int val)
        : val_(val), less_than_(0), count_(1), left_(nullptr), right_(nullptr) {
    }
  };

  int insert(Node **parent, Node *node, int val) {
    if (!node) {
      *parent = new Node(val);
      return 0;
    } else if (val < node->val_) {
      // 左子数的个数统计都在当前这个节点上，如果
      // 左子数为空此field的值还是为零
      node->less_than_++;
      return insert(&node->left_, node->left_, val);
    } else if (val == node->val_) {
      node->count_++;
      return node->less_than_;
    } else {
      return node->less_than_ + node->count_ +
             insert(&node->right_, node->right_, val);
    }
  }
};
