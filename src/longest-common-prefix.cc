// http://leetcode.com/problems/longest-common-prefix/description/
#include "xxx.h"

class Solution {
public:
  string longestCommonPrefix(vector<string> &strs) {
    if (strs.empty()) {
      return "";
    }

    int minlen = numeric_limits<int>::max();
    const int m = strs.size();
    for (auto s : strs) {
      minlen = min(minlen, (int)s.size());
    }
    int j = 0;
    for (; j < minlen; ++j) {
      for (int i = 1; i < m; ++i) {
        if (strs[i][j] != strs[0][j]) {
          goto outer;
        }
      }
    }
  outer:
    return strs[0].substr(0, j);
  }
};

int main() {
  Solution so;
  vector<string> input{"flower","flow","flight"};
  auto ret = so.longestCommonPrefix(input);
  cout << ret << endl;
}
