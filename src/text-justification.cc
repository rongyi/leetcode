// http://leetcode.com/problems/text-justification/description/
#include "one.h"

class Solution {
public:
  vector<string> fullJustify(vector<string> &words, int maxWidth) {
    vector<string> ret;
    int i = 0;
    const int n = words.size();
    while (i < n) {
      int j = i;
      int len = 0;
      // n个单词加上至少n-1个空格
      while (j < n && len + words[j].size() + (j - i) <= maxWidth) {
        len += words[j++].size();
      }
      string cur;
      // 判断的时候已经加上至少一个空格，所以这里的space初始值一定是大于0的
      int space = maxWidth - len;
      for (int k = i; k < j; ++k) {
        cur += words[k];
        if (space <= 0) {
          continue;
        }
        int tmp;
        // 这处理的是最后一行，最后一行空格尽量往右放，之前的都是一个空格正常情况
        if (j == words.size()) {
          // 最后一个字处理
          if (j - k == 1) {
            tmp = space;
          } else {
            // 否则就正常1个
            tmp = 1;
          }
        } else {
          if (j - k - 1 > 0) {
            if (space % (j - k - 1) == 0) {
              tmp = space / (j - k - 1);
            } else {
              tmp = space / (j - k - 1) + 1;
            }
          } else {
            tmp = space;
          }
        }
        cur.append(tmp, ' ');
        space -= tmp;
      }
      ret.push_back(cur);
      i = j;
    }

    return ret;
  }
};
