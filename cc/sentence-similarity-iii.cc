// http://leetcode.com/problems/sentence-similarity-iii/description/
#include "xxx.hpp"

class Solution {
public:
  bool areSentencesSimilar(string s1, string s2) {
    auto ws1 = words(s1);
    auto ws2 = words(s2);

    // 两边拉起来，然后去头去尾
    while (!ws1.empty() && !ws2.empty() && (ws1.front() == ws2.front())) {
      ws1.pop_front();
      ws2.pop_front();
    }

    while (!ws1.empty() && !ws2.empty() && (ws1.back() == ws2.back())) {
      ws1.pop_back();
      ws2.pop_back();
    }

    if (ws1.size() == 0 || ws2.size() == 0) {
      return true;
    }

    return false;
  }

private:
  deque<string> words(string &s) {
    int n = s.size();
    deque<string> ret;
    for (int i = 0; i < n;) {
      int j = i;
      while (j < n && s[j] != ' ') {
        j++;
      }
      auto tmp = s.substr(i, j - i);
      ret.push_back(tmp);
      i = j + 1;
    }

    return ret;
  }
};
