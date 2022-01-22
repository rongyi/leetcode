// http://leetcode.com/problems/check-if-two-string-arrays-are-equivalent/description/
#include "xxx.hpp"

class Solution {
public:
  bool arrayStringsAreEqual(vector<string> &word1, vector<string> &word2) {
    auto flat = [](vector<string> &lst) -> string {
      ostringstream ss;
      for (auto &s : lst) {
        ss << s;
      }
      return ss.str();
    };
    return flat(word1) == flat(word2);
  }
};
