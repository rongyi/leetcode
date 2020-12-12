// http://leetcode.com/problems/make-the-string-great/description/
#include "xxx.h"

class Solution {
public:
  string makeGood(string s) {
    string ret;
    bool push_last = true;
    for (int i = 0; i < s.size() - 1; ++i) {
      // bad case
      if (s[i] != s[i + 1] && tolower(s[i]) == tolower(s[i + 1])) {
        if (i == s.size() - 2) {
          push_last = false;
        }
        i++;
        continue;
      }
      ret.push_back(s[i]);
    }

    if (push_last) {
      ret.push_back(s.back());
    }

    if (ret == "" || ret == s) {
      return ret;
    }

    return makeGood(ret);
  }
};

int main() {
  Solution so;
  so.makeGood("abBAcC");
}
