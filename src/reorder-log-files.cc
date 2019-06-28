// http://leetcode.com/problems/reorder-log-files/description/
#include "xxx.h"

class Solution {
public:
  vector<string> reorderLogFiles(vector<string> &logs) {
    vector<string> digits;
    vector<string> letters;
    for (auto &l : logs) {
      char check = l[l.find(' ') + 1];
      if (isdigit(check)) {
        digits.push_back(l);
      } else {
        letters.push_back(l);
      }
    }
    sort(letters.begin(), letters.end(), [](const string &l, const string &r) {
      auto subl = l.substr(l.find(' ') + 1);
      auto subr = r.substr(r.find(' ') + 1);
      if (subl != subr) {
        return subl < subr;
      }
      return l.substr(0, l.find(' ')) < r.substr(0, r.find(' '));
    });
    vector<string> ret;
    for (auto &s : letters) {
      ret.push_back(s);
    }
    for (auto &s : digits) {
      ret.push_back(s);
    }

    return ret;
  }
};
