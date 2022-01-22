// http://leetcode.com/problems/longest-nice-substring/description/
#include "xxx.hpp"

class Solution {
public:
  Solution() : ret_("") {}
  // 又是被喷的很惨
  string longestNiceSubstring(string s) {
    const int n = s.size();
    vector<int> state(26, 0);
    for (auto &c : s) {
      if (isupper(c)) {
        state[c - 'A'] |= 2;
      } else {
        state[c - 'a'] |= 1;
      }
    }
    int i = 0;
    while (i < n) {
      int j = i;
      while (j < n && state[tolower(s[j]) - 'a'] == 3) {
        j++;
      }
      int cur = j - i;
      if (cur == n) {
        ret_ = s;
        break;
      }
      // 这里递归下去，下一层去判断
      if (cur > ret_.size()) {
        longestNiceSubstring(s.substr(i, cur));
      }

      while (j < n && state[tolower(s[j]) - 'a'] != 3) {
        ++j;
      }
      i = j;
    }
    return ret_;
  }

private:
  string ret_;
};

int main() {
  Solution so;
  so.longestNiceSubstring("YazaAay");
}
