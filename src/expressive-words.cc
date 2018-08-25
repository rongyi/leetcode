// http://leetcode.com/problems/expressive-words/description/
#include "one.h"

class Solution {
public:
  int expressiveWords(string S, vector<string> &words) {
    int ret = 0;
    for (auto w : words) {
      if (match(S, w)) {
        ++ret;
      }
    }
    return ret;
  }
  bool match(const string &s, const string &word) {
    int i = 0;
    int j = 0;
    const int sn = s.size();
    const int wn = word.size();
    while (i < sn && j < wn) {
      if (s[i++] != word[j++]) {
        return false;
      }
      int counts = 1;
      int countw = 1;
      while (i < sn && s[i] == s[i - 1]) {
        ++counts;
        ++i;
      }
      while (j < wn && word[j] == word[j - 1]) {
        ++countw;
        ++j;
      }
      if ((counts == countw) || (counts >= 3 && (countw < counts))) {
        continue;
      }
      return false;
    }
    return (i == sn) && (j == wn);
  }
};

int main() {
  Solution so;
  string S("heeellooo");
  vector<string> input{"hello"};
  string test{"hello"};
  auto ret = so.match(S, test);
  cout << ret << endl;
}
