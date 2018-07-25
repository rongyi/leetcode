// http://leetcode.com/problems/reorganize-string/description/
#include "one.h"

class Solution {
public:
  string reorganizeString(string s) {
    string ret = "";
    unordered_map<char, int> char_count;
    priority_queue<pair<int, char>> q;
    for (char c : s) {
      ++char_count[c];
    }
    for (auto cn : char_count) {
      if (cn.second > (s.size() + 1) / 2)
        return "";
      q.push({cn.second, cn.first});
    }

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
