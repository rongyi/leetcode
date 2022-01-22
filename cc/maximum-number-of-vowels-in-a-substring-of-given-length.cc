// http://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/description/
#include "xxx.hpp"

class Solution {
public:
  int maxVowels(string s, int k) {
    vector<int> count(26, 0);
    count['a' - 'a'] = 1;
    count['e' - 'a'] = 1;
    count['i' - 'a'] = 1;
    count['o' - 'a'] = 1;
    count['u' - 'a'] = 1;

    int ret = 0;
    int cur_window = 0;

    for (int i = 0; i < k; ++i) {
      cur_window += count[s[i] - 'a'];
      ret = max(ret, cur_window);
      // 都是，这个就是最大的了，没得选，不用比下去了
      if (ret == k) {
        return ret;
      }
    }

    for (int i = k; i < s.size(); ++i) {
      cur_window += count[s[i] - 'a'];
      cur_window -= count[s[i - k] - 'a'];
      ret = max(ret, cur_window);
      // 同上
      if (ret == k) {
        return k;
      }
    }
    return ret;
  }
};
