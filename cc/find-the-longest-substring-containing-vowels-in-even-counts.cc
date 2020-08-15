// http://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/find-the-longest-substring-containing-vowels-in-even-counts/discuss/534135/C%2B%2BJava-with-picture
  int findTheLongestSubstring(string s) {
    // mask for 'a' 'o' 'e' 'i' 'u'
    int table[26] = {1, 0, 0, 0, 2, 0, 0, 0,  4, 0, 0, 0, 0,
                     0, 8, 0, 0, 0, 0, 0, 16, 0, 0, 0, 0, 0};

    int ret = 0;
    // indicator of even count
    int mask = 0;
    // total combination of all 5 mask
    vector<int> total(32, -1);

    for (int i = 0; i < s.size(); ++i) {
      // mask的值为0代表的就是出现元音的次数为偶数次
      // 而且只要 mask[i] == mask[j] 则
      // string [i + 1, j+1]元音出现的次数肯定是偶数次
      mask ^= table[s[i] - 'a'];
      // 为后面的相同的mask做标记，只要标记过一次就可以了，因为选的是最长的
      if (mask != 0 && total[mask] == -1) {
        total[mask] = i;
      }
      ret = max(ret, i - total[mask]);
    }

    return ret;
  }
};
