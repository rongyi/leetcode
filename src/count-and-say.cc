// http://leetcode.com/problems/count-and-say/description/
#include "one.h"

class Solution {
public:
  // 对于重复的，找出重复次数，
  // 对于不重复的说一个X，
  string countAndSay(int n) {
    string initial{"1"};
    for (int i = 0; i < n - 1; ++i) {
      stringstream cur;
      const int len = initial.size();

      for (int j = 0; j < len;) {
        char c = initial[j];
        int start = j;
        while (j + 1 < len && initial[j + 1] == c) {
          j++;
        }
        if (j == start) {
          cur << '1' << c;
        } else {
          cur << j - start + 1 << c;
        }
        j++;
      }

      initial = cur.str();
    }
    return initial;
  }
};
int main() {
  Solution so;
  auto ret = so.countAndSay(5);
  cout << ret << endl;
}
