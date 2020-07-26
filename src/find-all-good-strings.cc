// http://leetcode.com/problems/find-all-good-strings/description/
#include "xxx.h"

// 一年多没有遇到这么难的题目
class Solution {
public:
  int findGoodStrings(int n, string s1, string s2, string evil) {
    mod_ = pow(10, 9) + 7;

    return dfs(0, 0, true, true, n, s1, s2, evil, computeLPS(evil));
  }
  int dfs(int i, int evilMatched, bool leftBound, bool rightBound, int n,
          string &s1, string &s2, string &evil, const vector<int> &lps) {
    if (evilMatched == evil.size()) {
      return 0;
    }
    if (i == n) {
      return 1;
    }
    if (dp_[i][evilMatched][leftBound][rightBound]) {
      return dp_[i][evilMatched][leftBound][rightBound];
    }
    char from = leftBound ? s1[i] : 'a';
    char to = rightBound ? s2[i] : 'z';

    int ret = 0;

    for (char c = from; c <= to; c++) {
      int j = evilMatched;
      while (j > 0 && evil[j] != c) {
        j = lps[j - 1];
      }
      if (c == evil[j]) {
        j++;
      }
      ret += dfs(i + 1, j, leftBound && (c == from), rightBound && (c == to), n,
                 s1, s2, evil, lps);
      ret %= mod_;
    }

    dp_[i][evilMatched][leftBound][rightBound] = ret;
    return dp_[i][evilMatched][leftBound][rightBound];
  }

  vector<int> computeLPS(const string &str) { // Longest Prefix also Suffix
    int n = str.size();
    vector<int> lps = vector<int>(n);
    for (int i = 1, j = 0; i < n; i++) {
      while (j > 0 && str[i] != str[j]) {
        j = lps[j - 1];
      }
      if (str[i] == str[j])
        lps[i] = ++j;
    }
    return lps;
  }

private:
  int dp_[501][50][2][2];
  int mod_;
};

int main() {
  Solution so;
  string s{"abcabcabcabe"};
  auto ret = so.computeLPS(s);
  for (auto i : ret) {
    cout << i << " ";
  }
  cout << endl;
}
