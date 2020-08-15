// http://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/description/
#include "xxx.h"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode *sortedArrayToBST(vector<int> &nums) {
    const int n = nums.size();

    return doSort(nums, 0, n);
  }

private:
  TreeNode *doSort(vector<int> &nums, int begin, int end) {
    const auto len = end - begin;
    if (len <= 0) {
      return nullptr;
    }
    auto mid = begin + len / 2;
    TreeNode *root = new TreeNode(nums[mid]);
    root->left = doSort(nums, begin, mid);
    root->right = doSort(nums, mid + 1, end);

    return root;
  }
};
