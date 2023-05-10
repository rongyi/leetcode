// http://leetcode.com/problems/serialize-and-deserialize-binary-tree/description/
#include "xxx.hpp"

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
  // Encodes a tree to a single string.
  // a full tree
  string serialize(TreeNode *root) {
    if (!root) {
      return "";
    }

    ostringstream oss;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur) {
        oss << to_string(cur->val) << ",";
        q.push(cur->left);
        q.push(cur->right);
      } else {
        oss << "nil,";
      }
    }

    return oss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    if (data.empty()) {
      return nullptr;
    }
    int i = 0;
    int j = data.find(',', i);

    queue<TreeNode *> q;
    TreeNode *root = new TreeNode(stoi(data.substr(0, j - i)));
    q.push(root);

    while (!q.empty()) {
      auto cur = q.front();

      // left
      i = j + 1;
      j = data.find(',', i);

      string tmp = data.substr(i, j - i);
      if (tmp != "nil") {
        cur->left = new TreeNode(stoi(tmp));
        q.push(cur->left);
      }

      // right
      i = j + 1;
      j = data.find(',', i);

      tmp = data.substr(i, j - i);
      if (tmp != "nil") {
        cur->right = new TreeNode(stoi(tmp));
        q.push(cur->right);
      }
      q.pop();
    }

    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
