// http://leetcode.com/problems/longest-word-in-dictionary/description/

#include "xxx.hpp"

class Solution {
public:
  string longestWord(vector<string> &words) {
    sort(words.begin(), words.end());
    unordered_set<string> cache;
    string ret{};
    for (auto &w : words) {
      if (w.size() == 1 ||
          cache.find(w.substr(0, w.size() - 1)) != cache.end()) {
        // 排好序遇到的第一个就是字符排序最小的，否则只有更长的时候才可以
        if (w.size() > ret.size()) {
          ret = w;
        }
        cache.insert(w);
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<string> input{"w", "wo", "wor", "worl", "world"};
  auto ret = so.longestWord(input);
  cout << ret << endl;
}
