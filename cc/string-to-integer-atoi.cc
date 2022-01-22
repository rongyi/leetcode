// http://leetcode.com/problems/string-to-integer-atoi/description/
#include "xxx.hpp"

class Solution {
public:
  int myAtoi(string str) {
    const int n = str.size();
    long long ret = 0;
    int i = 0;
    int sign = 1;
    // ignore leading spaces
    while (i < n && str[i] == ' ') {
      ++i;
    }
    if (i == n) {
      return 0;
    }
    // now we see sign '+' '-'
    if (str[i] == '+') {
      ++i;
    } else if (str[i] == '-') {
      ++i;
      sign = -1;
    }

    while (i < n && str[i] >= '0' && str[i] <= '9') {
      ret = ret * 10 + (str[i] - '0');
      i++;
      if (ret > numeric_limits<int>::max()) {
        if (sign == 1) {
          return numeric_limits<int>::max();
        }
        return numeric_limits<int>::min();
      }
    }
    return (int)ret * sign;
  }
};

int main() {
  Solution so;
  auto ret = so.myAtoi("9223372036854775808");
  cout << ret << endl;
}
