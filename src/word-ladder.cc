// http://leetcode.com/problems/word-ladder/description/
#include "one.h"

class Solution {
public:
  // 1. 将每个单词看成图的一个节点。
  // 2. 当单词s1改变一个字符可以变成存在于字典的单词s2时，则s1与s2之间有连接。
  // 3. 给定s1和s2，
  //    问题I转化成了求在图中从s1->s2的最短路径长度。
  //    而问题II转化为了求所有s1->s2的最短路径。
  int ladderLength(string beginWord, string endWord, vector<string> &wordList) {
    unordered_set<string> wset;
    for (auto s : wordList) {
      wset.insert(s);
    }
    // no possible transformation
    if (wset.find(endWord) == wset.end()) {
      return 0;
    }
    queue<pair<string, int>> q;
    q.push(make_pair(beginWord, 1));

    while (!q.empty()) {
      string cur = q.front().first;
      int cur_step = q.front().second;
      if (cur == endWord) {
        return cur_step;
      }
      q.pop();
      auto neibs = findNeibor(cur, wset);
      for (auto n : neibs) {
        q.push(make_pair(n, cur_step + 1));
      }
    }

    return 0;
  }

private:
  vector<string> findNeibor(string &s, unordered_set<string> &dict) {
    vector<string> ret;
    for (int i = 0; i < s.size(); ++i) {
      auto origin = s[i];
      for (int j = 0; j < 26; j++) {
        if (origin == 'a' + j) {
          continue;
        }
        s[i] = 'a' + j;
        if (dict.find(s) != dict.end()) {
          ret.push_back(s);
          // use it only once
          dict.erase(s);
        }
      }

      // remember to restore it back
      s[i] = origin;
    }
    return ret;
  }
};
