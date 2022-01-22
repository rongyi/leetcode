// http://leetcode.com/problems/repeated-string-match/description/
#include "xxx.hpp"

class Solution {
public:
  int repeatedStringMatch(string a, string b) {
    string as = a;
    // 很牛
    for (int ret = 1; ret <= b.length() / a.length() + 2; ret++, as += a) {
      if (as.find(b) != string::npos) {
        return ret;
      }
    }
    return -1;
  }
};

int main() {
  Solution so;
  // auto ret = so.repeatedStringMatch("abcd", "cdabcdab");
  // auto ret = so.repeatedStringMatch("baa", "abaab");
  auto ret = so.repeatedStringMatch("abcd", "bcdab");
  cout << ret << endl;
}
