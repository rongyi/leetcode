// https://leetcode.com/problems/count-palindromic-subsequences/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/count-palindromic-subsequences/solutions/2850466/c-java-python3-counting-prefixes-and-suffixes/?orderBy=most_votes
  int countPalindromes(string s) {
    int sz = s.size();
    vector<vector<vector<int>>> prev(
        sz, vector<vector<int>>(10, vector<int>(10, 0)));
    vector<vector<vector<int>>> suff(
        sz, vector<vector<int>>(10, vector<int>(10, 0)));
    vector<int> cnt(10, 0);

    for (int i = 0; i < sz; ++i) {
      int cur = s[i] - '0';
      if (i > 0) {
        for (int j = 0; j < 10; ++j) {
          for (int k = 0; k < 10; ++k) {
            prev[i][j][k] = prev[i - 1][j][k];
            if (k == cur) {
              prev[i][j][k] += cnt[j];
            }
          }
        }
      }

      cnt[cur]++;
    }
    cnt = vector<int>(10, 0);
    for (int i = sz - 1; i >= 0; --i) {
      int cur = s[i] - '0';
      if (i < sz - 1) {
        for (int j = 0; j < 10; ++j) {
          for (int k = 0; k < 10; ++k) {
            suff[i][j][k] = suff[i + 1][j][k];
            if (k == cur) {
              suff[i][j][k] += cnt[j];
            }
          }
        }
      }

      cnt[cur]++;
    }
    cout << "here" << endl;
    long long ret = 0;

    for (int i = 2; i < sz - 2; ++i) {
      for (int j = 0; j < 10; ++j) {
        for (int k = 0; k < 10; ++k) {
          ret = (ret + 1ll * prev[i - 1][j][k] * suff[i + 1][j][k]) % mod_;
        }
      }
    }

    return ret;
  }

private:
  int mod_ = 1e9 + 7;
};
