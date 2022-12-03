// https://leetcode.com/problems/edges-of-binary-tree-after-subtree-removal-queries/
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
class Solution {
public:
  vector<int> treeQueries(TreeNode *root, vector<int> &queries) {
    edges(root);

    peek_other_side(root->left, right_edges_[root->val], 1);
    peek_other_side(root->right, left_edges_[root->val], 1);

    vector<int> ret;
    for (auto &q : queries) {
      ret.push_back(otherside_max_edges_[q]);
    }

    return ret;
  }

private:
  // max edges to leaf
  // empty tree return 0
  // single node return 1
  // this question ask the edge, so the answer is edges - 1
  int edges(TreeNode *cur) {
    if (cur == nullptr) {
      return 0;
    }
    int lh = edges(cur->left);
    int rh = edges(cur->right);
    left_edges_[cur->val] = lh;
    right_edges_[cur->val] = rh;

    return max(lh, rh) + 1;
  }

  // afap: as far as possible
  // depth: the depth of node cur
  void peek_other_side(TreeNode *cur, int afap, int depth) {
    if (cur == nullptr) {
      return;
    }
    otherside_max_edges_[cur->val] = afap;
    // if the other side is deeper, we pick depth + right_edges_[cur->val]
    // if current size is deeper, we just pick the depth, that is depth + 1
    // either way we pick the longest
    peek_other_side(cur->left, max(afap, depth + right_edges_[cur->val]),
                    depth + 1);
    peek_other_side(cur->right, max(afap, depth + left_edges_[cur->val]),
                    depth + 1);
  }

private:
  // left child edges
  map<int, int> left_edges_;
  // right child edges
  map<int, int> right_edges_;
  // remove current node, cache the edges of the other side
  map<int, int> otherside_max_edges_;
};
