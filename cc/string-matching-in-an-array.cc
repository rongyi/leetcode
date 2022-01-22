// http://leetcode.com/problems/string-matching-in-an-array/description/
#include "xxx.hpp"

class Solution {
public:
  vector<string> stringMatching(vector<string> &words) {
    sort(words.begin(), words.end(),
         [](auto &l, auto &r) -> bool { return l.size() < r.size(); });
    vector<string> ret;
    for (int i = 0; i < words.size(); ++i) {
      auto &cur = words[i];
      for (int j = i + 1; j < words.size(); ++j) {
        if (words[j].find(cur) != string::npos) {
          ret.push_back(cur);
          break; // the inner loop
        }
      }
    }

    return ret;
  }
};
