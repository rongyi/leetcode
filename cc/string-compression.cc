// http://www.lintcode.com/zh-cn/problem/string-compression
#include "xxx.hpp"

class Solution {
public:
  int compress(vector<char> &chars) {
    const int n = chars.size();
    int cur = 0;
    for (int i = 0, j = 0; i < n; i = j) {
      while (j < n && chars[j] == chars[i]) {
        ++j;
      }
      chars[cur++] = chars[i];
      if (j - i == 1) {
        continue;
      }
      for (auto c : to_string(j - i)) {
        chars[cur++] = c;
      }
    }
    return cur;
  }
};

int main() {
  Solution so;
  vector<char> input{'a', 'a', 'b', 'b'};
  auto i = so.compress(input);
  cout << i << endl;
  for (auto c : input) {
    cout << c;
  }
  cout << endl;
}
