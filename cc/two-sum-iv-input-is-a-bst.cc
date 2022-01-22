// http://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/
#include "xxx.hpp"

class Solution {
public:
  bool findTarget(TreeNode *root, int k) {
    vector<int> nums;
    inorder(root, nums);
    const int n = nums.size();
    int i = 0;
    int j = n - 1;
    while (i < j) {
      auto sum = nums[i] + nums[j];
      if (sum == k) {
        return true;
      } else if (sum < k) {
        i++;
      } else {
        j--;
      }
    }
    return false;
  }
private:
  void inorder(TreeNode *root, vector<int> &nums) {
    if (!root) {
      return;
    }
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }
};
