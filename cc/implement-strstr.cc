// http://leetcode.com/problems/implement-strstr/description/
#include "xxx.h"

class Solution {
public:
  int strStr(string haystack, string needle) {
    const int m = haystack.size();
    const int n = needle.size();
    if (n == 0) {
      return 0;
    }
    if (m == 0 || n > m) {
      return -1;
    }
    for (int i = 0; i < m;) {
      int start = i;
      int j = 0;
      while (i < m && j < n && needle[j] == haystack[i]) {
        i++;
        j++;
      }
      if (j == n) {
        return start;
      }
      i = start + 1;
    }
    return -1;
  }
};

int main() {
  Solution so;
  auto ret = so.strStr("hello", "ll");
  cout << ret << endl;
}
