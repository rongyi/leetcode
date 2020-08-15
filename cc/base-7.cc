// http://leetcode.com/problems/base-7/description/
#include "xxx.h"

class Solution {
public:
  string convertToBase7(int num) {
    if (num == 0) {
      return "0";
    }

    string ret;
    bool negative = false;
    if (num < 0) {
      negative = true;
      num = abs(num);
    }

    while (num) {
      ret.push_back((num % 7) + '0');
      num /= 7;
    }
    reverse(ret.begin(), ret.end());

    if (negative) {
      ret.insert(ret.begin(), '-');
    }
    return ret;
  }
};
int main() {
  Solution so;
  auto ret = so.convertToBase7(100);
  cout << ret << endl;
}
