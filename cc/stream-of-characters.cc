// http://leetcode.com/problems/stream-of-characters/description/
#include "cstring"
#include "xxx.hpp"

class Trie {
public:
  Trie *arr_[26] = {};
  bool is_leaf_ = false;
  Trie() : is_leaf_(false) {}

  void insert(string &w, int pos = 0) {
    if (pos == w.size()) {
      is_leaf_ = true;
    } else {
      auto idx = w[pos] - 'a';
      if (arr_[idx] == nullptr) {
        arr_[idx] = new Trie();
      }
      arr_[idx]->insert(w, pos + 1);
    }
  }
  bool search(string &w, int pos) {
    if (is_leaf_ || pos == -1) {
      return is_leaf_;
    }
    auto idx = w[pos] - 'a';
    if (arr_[idx] == nullptr) {
      return false;
    }

    return arr_[idx]->search(w, pos - 1);
  }
};

class StreamChecker {
public:
  StreamChecker(vector<string> &words) {
    for (auto w : words) {
      reverse(w.begin(), w.end());
      t_.insert(w);
    }
  }

  bool query(char letter) {
    search_word_.push_back(letter);
    return t_.search(search_word_, search_word_.size() - 1);
  }

private:
  string search_word_;
  Trie t_;
};

/**
 * Your StreamChecker object will be instantiated and called as such:
 * StreamChecker* obj = new StreamChecker(words);
 * bool param_1 = obj->query(letter);
 */

int main() {
  vector<string> input{"cd", "f", "kl"};
  StreamChecker sc(input);
  sc.query('a');
  sc.query('b');
  sc.query('c');
  auto ret = sc.query('d');
  cout << ret << endl;
}
