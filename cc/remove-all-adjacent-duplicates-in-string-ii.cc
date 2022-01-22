// http://leetcode.com/problems/remove-all-adjacent-duplicates-in-string-ii/description/
#include "xxx.hpp"

class Solution {
public:
  string removeDuplicates(string s, int k) {
    vector<char> stk;
    for (auto &c : s) {
      if (stk.empty() || stk.size() < k - 1) {
        stk.push_back(c);
      } else {
        bool same = true;
        int i = 0;
        int j = stk.size() - 1;
        while (i < k - 1) {
          if (stk[j] != c) {
            same = false;
            break;
          }
          j--;
          i++;
        }
        if (same) {
          for (int i = 0; i < k - 1; ++i) {
            stk.pop_back();
          }
        } else {
          stk.push_back(c);
        }
      }
    }
    string ret;
    for (auto &c : stk) {
      ret.push_back(c);
    }
    return ret;
  }
};
