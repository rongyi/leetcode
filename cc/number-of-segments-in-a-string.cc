// http://leetcode.com/problems/number-of-segments-in-a-string/description/
#include "xxx.h"

class Solution {
public:
  int countSegments(string s) {
    if (s.empty()) {
      return 0;
    }
    int i = 0;
    while (s[i] == ' ') {
      i++;
    }
    if (i == s.size()) {
      return 0;
    }
    s = s.substr(i);
    int j = s.size() - 1;
    while (s[j] == ' ') {
      --j;
    }
    s = s.substr(0, j + 1);
    cout << s << "||" << endl;

    int space = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (isspace(s[i])) {
        ++space;
        while (isspace(s[i])) {
          ++i;
        }
        // for循环还要加，所以找回来一步
        --i;
      }
    }
    return space + 1;
  }
};

int main() {
  Solution so;
  auto ret = so.countSegments("         a   ");
  cout << ret << endl;
}
