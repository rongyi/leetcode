// http://leetcode.com/problems/maximum-score-after-splitting-a-string/description/
#include "xxx.hpp"

class Solution {
public:
  int maxScore(string s) {
    vector<int> count_one(s.size(), 0);
    vector<int> count_zero(s.size(), 0);
    int count = 0;
    for (int i = 0; i < s.size(); ++i) {
      if (s[i] == '0') {
        ++count;
      }
      count_zero[i] = count;
    }

    // all zero
    if (count == s.size()) {
      return count - 1;
    }

    count = 0;
    for (int i = s.size() - 1; i >= 0; --i) {
      if (s[i] == '1') {
        ++count;
      }
      count_one[i] = count;
    }
    // all one
    if (count == s.size()) {
      return count - 1;
    }

    int ret = 0;
    // 两边至少留一个
    for (int i = 1; i < s.size() - 1; ++i) {
      ret = max(ret, count_one[i] + count_zero[i]);
    }

    return ret;
  }
};

int main() {
  Solution so;
  // auto ret = so.maxScore("011101");
  auto ret = so.maxScore("11100");
  cout << ret << endl;
}
