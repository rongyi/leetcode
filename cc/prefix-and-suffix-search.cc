// http://leetcode.com/problems/prefix-and-suffix-search/description/
#include "xxx.hpp"

class Trie {
public:
  Trie() { children_ = vector<Trie *>(26, nullptr); }
  ~Trie() {
    for (int i = 0; i < 26; i++) {
      if (children_[i]) {
        delete children_[i];
      }
    }
  }
  void add(const string &word, int pos, int cur_weight) {
    weight_.push_back(cur_weight);
    if (pos < word.size()) {
      auto index = word[pos] - 'a';
      if (!children_[index]) {
        children_[index] = new Trie();
      }
      children_[index]->add(word, pos + 1, cur_weight);
    }
  }
  vector<int> find(const string &prefix, int pos) {
    if (pos == prefix.size()) {
      return weight_;
    } else {
      if (!children_[prefix[pos] - 'a']) {
        return {};
      }
      return children_[prefix[pos] - 'a']->find(prefix, pos + 1);
    }
  }

private:
  vector<int> weight_;
  vector<Trie *> children_;
};

class WordFilter {
public:
  WordFilter(vector<string> &words) {
    for (int i = 0; i < words.size(); i++) {
      string cur = words[i];
      forward_.add(cur, 0, i);

      reverse(cur.begin(), cur.end());
      backward_.add(cur, 0, i);
    }
  }

  int f(string prefix, string suffix) {
    auto fwd = forward_.find(prefix, 0);

    reverse(suffix.begin(), suffix.end());
    auto bcw = backward_.find(suffix, 0);

    auto fiter = fwd.rbegin();
    auto biter = bcw.rbegin();
    while (fiter != fwd.rend() && biter != bcw.rend()) {
      if (*fiter == *biter) {
        return *fiter;
      } else if (*fiter > *biter) {
        fiter++;
      } else {
        biter++;
      }
    }

    return -1;
  }

private:
  Trie forward_;
  Trie backward_;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
