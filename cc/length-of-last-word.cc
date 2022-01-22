// http://leetcode.com/problems/length-of-last-word/description/
#include "xxx.hpp"

class Solution {
public:
  int lengthOfLastWord2(string s) {
    auto j = s.find_last_not_of(' ');
    if (j == string::npos) {
      return 0;
    }
    auto i = s.find_last_of(' ', j);

    return j - i;
  }

  int lengthOfLastWord(string str) {
    const int n = str.size();
    int ret = 0;
    for (int i = 0; i < n;) {
      if (str[i++] != ' ') {
        ++ret;
      } else if (i < n && str[i] == ' ') {
        ret = 0;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  auto ret = so.lengthOfLastWord("a ");
  cout << ret << endl;
}
