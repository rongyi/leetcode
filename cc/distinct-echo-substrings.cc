// http://leetcode.com/problems/distinct-echo-substrings/description/
#include "xxx.hpp"

class Solution {
public:
  // substring can be split into two identical part
  int distinctEchoSubstrings(string text) {
    unordered_set<string> ret;
    // TLS version
    // for (int i = 0; i < text.size(); i++) {
    //   for (int len = 1; i + len + len <= text.size(); ++len) {
    //     const auto a = text.substr(i, len);
    //     const auto b = text.substr(i + len, len);
    //     if (a == b) {
    //       ret.insert(a);
    //     }
    //   }
    // }

    // split point
    for (auto split = 1; split < text.size() - 1; ++split) {
      for (auto sz = 1; split - sz >= 0 && split + sz - 1 < text.size(); ++sz) {
        // no substr, or we can use string_view but it's c++17
        if (text.compare(split - sz, sz, text, split, sz) == 0) {
          ret.insert(text.substr(split, sz));
        }
      }
    }

    return ret.size();
  }
};
