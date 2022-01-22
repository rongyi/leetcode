// http://leetcode.com/problems/longest-repeating-character-replacement/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/longest-repeating-character-replacement/discuss/91285/Sliding-window-similar-to-finding-longest-substring-with-k-distinct-characters
  // 先不看k，如果是整个字符串替换，替换次数最少是多少？
  // ==> 整个字符串长度 - 里面出现最多的那个字符出现的次数
  // 加上K的约束呢？
  // ==> 在子字符串中 整个子串的长度 - 出现次数最多的那个字符出现的次数 <= k
  int characterReplacement(string s, int k) {
    int ret = 0;
    // 当前sliding window中出现次数最多的那个字符
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
