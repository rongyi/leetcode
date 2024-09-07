// http://leetcode.com/problems/find-and-replace-pattern/description/
#include "xxx.hpp"
#include <unordered_map>

class Solution {
public:
  // order matters
  vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
    auto expect = normalize(pattern);
    vector<string> ret;

    for (auto &s : words) {
      auto cur = normalize(s);
      if (cur == expect) {
        ret.push_back(s);
      }
    }

    return ret;
  }
  vector<int> normalize(string &s) {
    vector<int> ret(s.length(), 0);
    unordered_map<char, int> to_index;

    for (auto &c : s) {
      auto sz = to_index.size();
      if (to_index.contains(c)) {
        ret.push_back(to_index[c]);
      } else {
        ret.push_back(sz);
        to_index[c] = sz;
      }
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<string> words{"mee"};
  so.findAndReplacePattern(words, "abb");
}
