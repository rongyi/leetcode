// http://leetcode.com/problems/longest-substring-of-all-vowels-in-order/description/
#include "xxx.h"

class Solution {
public:
  int longestBeautifulSubstring(string word) {
    int n = word.size();

    if (n < 5) {
      return 0;
    }
    int ret = 0;
    //  这么丑的代码竟然一次过了，哈哈哈哈哈~~~
    for (int i = 0; i < n;) {
      while (i < n && word[i] != 'a') {
        i++;
      }
      // now i stop at first 'a'
      int j = i;
      while (j < n && word[j] == 'a') {
        j++;
      }
      if (j == n || (j < n && word[j] != 'e')) {
        i = j;
        continue;
      }

      while (j < n && word[j] == 'e') {
        j++;
      }

      if (j == n || (j < n && word[j] != 'i')) {
        i = j;
        continue;
      }
      while (j < n && word[j] == 'i') {
        j++;
      }

      if (j == n || (j < n && word[j] != 'o')) {
        i = j;
        continue;
      }
      while (j < n && word[j] == 'o') {
        j++;
      }

      if (j == n || (j < n && word[j] != 'u')) {
        i = j;
        continue;
      }
      while (j < n && word[j] == 'u') {
        j++;
      }
      ret = max(ret, j - i);
      i = j;
    }
    return ret;
  }
};
