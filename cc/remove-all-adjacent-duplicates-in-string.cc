// http://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/
#include "xxx.h"

class Solution {
public:
  string removeDuplicates(string S) {
    vector<char> stk;
    for (auto c : S) {
      if (stk.empty()) {
        stk.push_back(c);
      } else {
        if (c == stk.back()) {
          stk.pop_back();
        } else {
          stk.push_back(c);
        }
      }
    }
    string ret;
    for (auto c : stk) {
      ret.push_back(c);
    }
    return ret;
  }
};

int main() {
  Solution so;
  so.removeDuplicates("abbaca");
}
