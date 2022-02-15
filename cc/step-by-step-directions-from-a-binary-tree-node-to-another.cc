// https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  string getDirections(TreeNode *root, int startValue, int destValue) {
    string to_start;
    string to_target;

    find(root, startValue, to_start);
    find(root, destValue, to_target);

    while (!to_start.empty() && !to_target.empty() &&
           to_start.back() == to_target.back()) {
      to_start.pop_back();
      to_target.pop_back();
    }

    reverse(to_target.begin(), to_target.end());
    return string(to_start.size(), 'U') + to_target;
  }

private:
  // find return the path in *reverse* order
  bool find(TreeNode *n, int val, string &path) {
    if (n->val == val) {
      return true;
    }
    if (n->left && find(n->left, val, path)) {
      path.push_back('L');
    } else if (n->right && find(n->right, val, path)) {
      path.push_back('R');
    }

    return !path.empty();
  }
};

class SolutionXX {
public:
  // same logic, but the implemetation is not as votrubac's
  string getDirectionsMLE(TreeNode *root, int startValue, int destValue) {
    if (startValue == root->val) {
      return path(root, destValue, "");
    }
    string to_start = path(root, startValue, "");
    if (destValue == root->val) {
      return string(to_start.size(), 'U');
    }
    string to_target = path(root, destValue, "");
    // drop common prefix
    int i = 0;
    for (; i < to_start.size() && i < to_target.size();) {
      if (to_start[i] == to_target[i]) {
        i++;
      } else {
        break;
      }
    }

    if (i < to_start.size()) {
      to_start = to_start.substr(i);
    } else {
      to_start = "";
    }
    if (i < to_target.size()) {
      to_target = to_target.substr(i);
    } else {
      to_target = "";
    }

    return string(to_start.size(), 'U') + to_target;
  }

private:
  string path(TreeNode *cur_node, int target_val, string cur_path) {
    // not found in this tree?
    if (!cur_node) {
      return "";
    }
    if (cur_node->val == target_val) {
      return cur_path;
    }
    string l = path(cur_node->left, target_val, cur_path + "L");
    // not in l? then it must be in right child
    if (l == "") {
      return path(cur_node->right, target_val, cur_path + "R");
    }
    return l;
  }
};
