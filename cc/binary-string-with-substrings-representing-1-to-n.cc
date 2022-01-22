// http://leetcode.com/problems/binary-string-with-substrings-representing-1-to-n/description/
#include "xxx.hpp"

class Solution {
public:
  // 喷的很惨
  bool queryString(string S, int N) {
    while (N > 0) {
      // 这里需要记住一下
      auto s = bitset<32>(N--).to_string();
      if (S.find(s.substr(s.find("1"))) == string::npos) {
        return false;
      }
    }
    return true;
  }
};

int main() {
  cout << bitset<32>(63).to_string() << endl;
}
