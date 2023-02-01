// http://leetcode.com/problems/string-to-integer-atoi/description/
#include "xxx.hpp"

class Solution {
public:
  int myAtoi(string s) {
    int sz = s.size();
    int i = 0;
    while (i < sz && s[i] == ' ') {
      i++;
    }
    if (i == sz) {
      return 0;
    }
    int sign = 1;
    if (s[i] == '+') {
      i++;
    } else if (s[i] == '-') {
      i++;
      sign = -1;
    }

    long long acc = 0;
    for (; i < sz; i++) {
      if (s[i] <= '9' && s[i] >= '0') {
        acc = acc * 10 + (s[i] - '0');
        if (sign * acc <= numeric_limits<int>::min()) {
          return numeric_limits<int>::min();
        } else if (sign * acc >= numeric_limits<int>::max()) {
          return numeric_limits<int>::max();
        }
      } else {
        break;
      }
    }
    return acc * sign;
  }
};

int main() {
  Solution so;
  auto ret = so.myAtoi("9223372036854775808");
  cout << ret << endl;
}
