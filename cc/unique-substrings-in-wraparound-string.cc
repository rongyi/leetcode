// http://leetcode.com/problems/unique-substrings-in-wraparound-string/description/
#include "xxx.hpp"

class Solution {
public:
  int findSubstringInWraproundString(string p) {
    vector<int> count(26, 0);
    int max_len = 0;
    for (int i = 0; i < p.size(); ++i) {
      // 'za' or 'ab'
      if (i > 0 && (p[i - 1] - p[i] == 25 || p[i] - p[i - 1] == 1)) {
        max_len++;
      } else {
        max_len = 1;
      }
      count[p[i] - 'a'] = max(count[p[i] - 'a'], max_len);
    }

    return accumulate(count.begin(), count.end(), 0);
  }
};
