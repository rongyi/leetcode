// http://leetcode.com/problems/longest-repeating-character-replacement/description/
#include "xxx.h"

class Solution {
public:
  int characterReplacement(string s, int k) {
    int ret = 0;
    int cur_max = 0;
    int start = 0;
    const int n = s.size();
    // all upper case
    vector<int> count(26, 0);
    for (int end = 0; end < n; end++) {
      count[s[end] - 'A']++;
      cur_max = max(cur_max, count[s[end] - 'A']);
      // 收缩
      while (end - start + 1 - cur_max > k) {
        count[s[start] - 'A']--;
        start++;
      }
      ret = max(ret, end - start + 1);
    }

    return ret;
  }
};
