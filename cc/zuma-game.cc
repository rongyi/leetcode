// http://leetcode.com/problems/zuma-game/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/zuma-game/discuss/97010/%22short%22-java-solution-beats-98
  int findMinStep(string board, string hand) {
    unordered_map<char, int> dict;
    for (auto h : hand) {
      dict[h]++;
    }
    // The number of balls in your hand won't exceed 5,
    max_count_ = 6;

    // why plus #? ==> 是为了处理最后的case，比如最后两个AA，这时候需要特殊处理，而加上
    // #呢，处理前面case和处理这个case一个代码，这里可以学习一下
    int ret = recur(board + '#', dict);

    return ret == max_count_ ? -1 : ret;
  }

private:
  int recur(string s, unordered_map<char, int> &dict) {
    s = shrink(s);

    if (s == "#") {
      return 0;
    }

    int ret = max_count_;
    int need = 0;
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        continue;
      }
      need = 3 - (j - i);
      if (dict[s[i]] >= need) {
        dict[s[i]] -= need;

        ret = min(ret, need + recur(s.substr(0, i) + s.substr(j), dict));

        dict[s[i]] += need;
      }

      i = j;
    }

    return ret;
  }

  string shrink(string s) {
    for (int i = 0, j = 0; j < s.size(); ++j) {
      if (s[i] == s[j]) {
        continue;
      }
      if (j - i >= 3) {
        return shrink(s.substr(0, i) + s.substr(j));
      } else {
        i = j;
      }
    }
    return s;
  }

private:
  int max_count_;
};
