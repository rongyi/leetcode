// http://leetcode.com/problems/replace-words/description/
#include "xxx.h"

class Solution {
public:
  struct Node {
    bool is_leaf_;
    Node *child_[26];
  };
  Node *mkNode() {
    Node *ret = new Node;
    ret->is_leaf_ = false;
    for (int i = 0; i < 26; i++) {
      ret->child_[i] = nullptr;
    }
    return ret;
  }

  void insert(Node *root, string val) {
    Node *cur = root;
    for (auto c : val) {
      auto index = c - 'a';
      if (cur->child_[index] == nullptr) {
        cur->child_[index] = mkNode();
      }
      cur = cur->child_[index];
    }
    cur->is_leaf_ = true;
  }

  string shortestPrefix(Node *root, string value) {
    stringstream ss;
    Node *cur = root;
    for (int i = 0; i < value.size() && !cur->is_leaf_; i++) {
      auto idx = value[i] - 'a';
      // this is search, we do not create
      if (!cur->child_[idx]) {
        return "";
      }
      cur = cur->child_[idx];
      ss << value[i];
    }
    if (!cur->is_leaf_) {
      return "";
    }

    return ss.str();
  }

  string replaceWords(vector<string> &dict, string sentence) {
    Node *root = mkNode();
    for (auto s : dict) {
      insert(root, s);
    }
    stringstream ss(sentence);
    string word{};
    stringstream outss;

    while (ss >> word) {
      auto maybe = shortestPrefix(root, word);
      if (maybe == "") {
        outss << word << " ";
      } else {
        outss << maybe << " ";
      }
    }
    auto ret = outss.str();
    if (ret.size() > 0) {
      ret = ret.substr(0, ret.size() - 1);
    }

    return ret;
  }
};
int main() {
  Solution so;
  vector<string> input{"hello", "world"};
  so.replaceWords(input, "hellooooo a s s   dd");
}
