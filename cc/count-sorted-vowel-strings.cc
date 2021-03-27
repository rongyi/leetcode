// http://leetcode.com/problems/count-sorted-vowel-strings/description/
#include "xxx.h"

class Solution {
public:
  int countVowelStrings(int n) {
    int a = 1;
    int e = 1;
    int i = 1;
    int o = 1;
    int u = 1;

    while (n > 1) {
      a = (a + e + i + o + u);
      e = (e + i + o + u);
      i = (i + o + u);
      o = (o + u);
      // u = (u);
      n--;
    }

    return a + e + i + o + u;
  }
  int countVowelStringsTLS(int n) {
    string raw{"aeiou"};
    dfs(raw, "", 0, n);

    return words_.size();
  }

private:
  void dfs(string &raw, string cur, int i, int n) {
    if (cur.size() >= n) {
      words_.insert(cur);
      return;
    }
    if (i >= raw.size()) {
      return;
    }

    // 取当前字符，还想取当前字符
    dfs(raw, cur + raw[i], i, n);
    // 取当前字符，用一次就算了
    dfs(raw, cur + raw[i], i + 1, n);

    // 不取
    dfs(raw, cur, i + 1, n);
  }

private:
  unordered_set<string> words_;
};
int main() {
  Solution so;
  auto ret = so.countVowelStrings(1);
  cout << ret << endl;
}
