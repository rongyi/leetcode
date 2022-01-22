// http://leetcode.com/problems/excel-sheet-column-title/description/
#include "xxx.hpp"

class Solution {
public:
  // 实际就是进制的转换
  string convertToTitle(int n) {
    if (n == 0) {
      return 0;
    }
    vector<char> table(26, '0');
    for (int i = 0; i < 26; i++) {
      table[i] = 'A' + i;
    }
    stringstream ss;
    while (n) {
      auto real = n - 1;
      auto cur = real % 26;
      cout << cur << endl;
      ss << table[cur];
      n = real / 26;
    }
    auto ret = ss.str();
    reverse(ret.begin(), ret.end());

    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.convertToTitle(27);
  cout << ret << endl;
}
