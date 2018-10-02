// http://leetcode.com/problems/length-of-last-word/description/
#include "one.h"

class Solution {
public:
  int lengthOfLastWord(string s) {
    auto j = s.find_last_not_of(' ');
    if (j == string::npos) {
      return 0;
    }
    auto i = s.find_last_of(' ', j);

    return j - i;
  }
};

int main() {
  Solution so;
  auto ret = so.lengthOfLastWord(" ");
  cout << ret << endl;
}
