// http://leetcode.com/problems/regular-expression-matching/description/
#include "one.h"

class Solution {
public:
  bool isMatch(string s, string p) { return is(s.c_str(), p.c_str()); }

private:
  bool is(const char *s, const char *p) {
    if (*p == '\0') {
      return *s == '\0';
    }
    // no star, one by one exactly or dot match
    if (*(p + 1) != '*') {
      if (*p == *s || (*p == '.' && *s != '\0')) {
        return is(s + 1, p + 1);
      }

      return false;
    } else {
      while (*p == *s || (*p == '.' && *s != '\0')) {
        if (is(s, p + 2)) {
          return true;
        }
        // 这里就是1个或者多个的匹配
        s++;
      }
      // 直接跳过，也即使用*的0个匹配，遇到不等的，那就从上面跳出来，使用后续exp匹配了。
      return is(s, p + 2);
    }
  }
};

int main() {
  Solution so;
  auto ret = so.isMatch("aab", "c*a*b");
  cout << ret << endl;
}
