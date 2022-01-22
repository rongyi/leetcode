// http://leetcode.com/problems/implement-magic-dictionary/description/
#include "xxx.hpp"

class MagicDictionary {
public:
  /** Initialize your data structure here. */
  MagicDictionary() {}

  /** Build a dictionary through a list of words */
  void buildDict(vector<string> dict) {
    dict_ = dict;
    for (auto &w : dict) {
      lens_.insert(w.size());
    }
  }

  /** Returns if there is any word in the trie that equals to the given word
   * after modifying exactly one character */
  bool search(string word) {
    if (lens_.find(word.size()) == lens_.end()) {
      return false;
    }
    for (auto &w : dict_) {
      if (match(w, word)) {
        return true;
      }
    }

    return false;
  }

private:
  bool match(string &dict, string &pattern) {
    if (dict.size() != pattern.size()) {
      return false;
    }
    int prev_diff = -1;
    for (int i = 0; i < dict.size(); i++) {
      if (dict[i] != pattern[i]) {
        // already met a diff
        if (prev_diff != -1) {
          return false;
        }
        prev_diff = 1;
      }
    }

    return prev_diff == -1 ? false : true;
  }

private:
  vector<string> dict_;
  unordered_set<int> lens_;
};

/**
 * Your MagicDictionary object will be instantiated and called as such:
 * MagicDictionary* obj = new MagicDictionary();
 * obj->buildDict(dict);
 * bool param_2 = obj->search(word);
 */

int main() {
  MagicDictionary md{};
  vector<string> input{"hello", "leetcode"};
  md.buildDict(input);
  auto ret = md.search("hello");
  cout << ret << endl;
}
