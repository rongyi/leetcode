// http://leetcode.com/problems/text-justification/description/
#include "xxx.hpp"

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
          // 处理非最后一行的情况，所以这里空格要尽可能平均分配，不能平均把空格尽可能的分配在前面
          // 判断是否是最后一个字，是的，就尽可能平均分配，此时j已经是下一个区间的第一个字了，
          // 所以减1
          if (j - k - 1 > 0) {
            if (space % (j - k - 1) == 0) {
              tmp = space / (j - k - 1);
            } else {
              tmp = space / (j - k - 1) + 1;
            }
          } else {
            // 这一行的最后一个字符，后面剩多少就多少，全放在这里
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
