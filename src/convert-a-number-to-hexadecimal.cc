// http://leetcode.com/problems/convert-a-number-to-hexadecimal/description/
#include "xxx.h"

class Solution {
public:
  string toHex(int num) {
    const static string table{"0123456789abcdef"};
    string ret{};

    if (num == 0) {
      return "0";
    }

    int count = 0;
    while (num && count < 8) {
      int cur = num & 0xf;
      count++;
      num >>= 4;
      ret.push_back(table[cur]);
    }

    reverse(ret.begin(), ret.end());
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.toHex(-1);
  cout << ret << endl;
}
