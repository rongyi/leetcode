// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/
#include "xxx.h"

class Solution {
public:
  string removeOccurrences(string s, string part) {
    while (chunkdrop(s, part)) {
      ;
    }

    return s;
  }

private:
  // drop the part
  bool chunkdrop(string &s, string &part) {
    auto idx = s.find(part);
    if (idx == string::npos) {
      return false;
    }

    string tmp = s.substr(0, idx) + s.substr(idx + part.length());
    swap(tmp, s);

    return true;
  }
};
