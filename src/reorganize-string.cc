// http://leetcode.com/problems/reorganize-string/description/
#include "one.h"

class Solution {
public:
  string reorganizeString(string s) {
    string ret = "";
    // 记录每个字符出现的次数 char ==> count
    unordered_map<char, int> char_count;
    // 记录出现这么多次的字符, 按字数进行排序
    priority_queue<pair<int, char>> q;
    for (char c : s) {
      ++char_count[c];
    }
    for (auto cn : char_count) {
      if (cn.second > (s.size() + 1) / 2)
        return "";
      q.push({cn.second, cn.first});
    }

    // 然后每次出两个，把字符放一起，这样来保证相邻不重复
    // 相当于重组的一种方法，从出现多的到少的，一次一个一个的拿
    while (q.size() >= 2) {
      auto t1 = q.top();
      q.pop();
      auto t2 = q.top();
      q.pop();
      ret.push_back(t1.second);
      ret.push_back(t2.second);
      if (--t1.first > 0) {
        q.push(t1);
      }
      if (--t2.first > 0) {
        q.push(t2);
      }

    }
    if (q.size() > 0) {
      ret.push_back(q.top().second);
    }
    return ret;
  }
};
