// https://leetcode.com/problems/delete-duplicate-folders-in-system/
#include "xxx.hpp"

class Solution {
private:
  struct Node {
    string name_;
    map<string, Node *> next_;
    bool del_ = false;
    Node(string n = "") : name_(n) {}
  };

public:
  vector<vector<string>> deleteDuplicateFolder(vector<vector<string>> &paths) {
    Node root;
    for (auto &path : paths) {
      addPath(&root, path);
    }
    dedup(&root);
    for (auto &[_, next] : root.next_) {
      getPath(next);
    }
    return ret_;
  }

private:
  // just like trie construction
  void addPath(Node *node, vector<string> &path) {
    for (auto &c : path) {
      if (node->next_.count(c) == 0) {
        node->next_[c] = new Node(c);
      }
      node = node->next_[c];
    }
  }
  // use gdb to see the layer graph
  string dedup(Node *node) {
    string subfolder;
    for (auto &[_, next] : node->next_) {
      subfolder += dedup(next);
    }
    if (subfolder.size()) {
      if (seen_.count(subfolder)) {
        // either the origin and current match are all deleted
        seen_[subfolder]->del_ = node->del_ = true;
      } else {
        seen_[subfolder] = node;
      }
    }

    string ret = "(" + node->name_ + subfolder + ")";

    return ret;
  }
  void getPath(Node *node) {
    if (node->del_) {
      return;
    }
    path_.push_back(node->name_);
    ret_.push_back(path_);
    for (auto &[_, next] : node->next_) {
      getPath(next);
    }
    path_.pop_back();
  }

private:
  unordered_map<string, Node *> seen_;
  vector<vector<string>> ret_;
  vector<string> path_;
};

int main() {
  Solution so;
  vector<vector<string>> input{{"a"},      {"c"},      {"d"},
                               {"a", "b"}, {"c", "b"}, {"d", "a"}};
  so.deleteDuplicateFolder(input);
}
