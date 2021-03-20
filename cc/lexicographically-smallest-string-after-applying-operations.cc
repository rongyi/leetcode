// http://leetcode.com/problems/lexicographically-smallest-string-after-applying-operations/description/
#include "xxx.h"

class Solution {
public:
  // 就这么暴力破解下去，一眼看上去还以为有什么法子
  string findLexSmallestString(string s, int a, int b) {
    unordered_set<string> visits;
    string ret = s;
    dfs(visits, s, a, b, ret);

    return ret;
  }

private:
  void dfs(unordered_set<string> &visits, string cur, int a, int b,
           string &ret) {
    if (visits.count(cur)) {
      return;
    }
    visits.insert(cur);
    ret = min(ret, cur);

    dfs(visits, rotate(cur, b), a, b, ret);
    dfs(visits, add(cur, a), a, b, ret);
  }

  string rotate(string s, int x) {
    reverse(begin(s), end(s));
    reverse(begin(s), begin(s) + x);
    reverse(begin(s) + x, end(s));

    return s;
  }

  string add(string s, int x) {
    for (int i = 1; i < s.size(); i += 2) {
      s[i] = '0' + (s[i] - '0' + x) % 10;
    }

    return s;
  }
};
