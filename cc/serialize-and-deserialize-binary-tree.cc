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
  string serialize(TreeNode *root) {
    if (!root) {
      return "";
    }
    queue<TreeNode *> q;
    stringstream ss;
    q.push(root);
    while (!q.empty()) {
      auto cur = q.front();
      q.pop();
      if (cur) {
        ss << to_string(cur->val);
        ss << ",";

        q.push(cur->left);
        q.push(cur->right);
      } else {
        ss << "nil,";
      }
    }
    return ss.str();
  }

  // Decodes your encoded data to tree.
  TreeNode *deserialize(string data) {
    queue<TreeNode*> q;
    if (data.empty()) {
      return nullptr;
    }
    int i = 0;
    int j = data.find(',', i);
    TreeNode *root = new TreeNode(stoi(data.substr(0, j - i)));
    q.push(root);

    while (!q.empty()) {
      // left
      i = j + 1;
      j = data.find(',', i);
      auto cur = q.front();

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
// Codec codec;
// codec.deserialize(codec.serialize(root));

int main() {
  Codec so;
  TreeNode n1(1), n2(2), n3(3);
  n1.left = &n2;
  n1.right = &n3;

  auto ret = so.serialize(&n1);
  cout << ret << endl;
  cout << "===" << endl;

  string test = "1,";
  auto s = test.substr(0, test.find(',') - 0);
  cout << s << endl;
}
