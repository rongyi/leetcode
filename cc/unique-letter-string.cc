// http://leetcode.com/problems/unique-letter-string/description/
#include "xxx.hpp"

class Solution {
public:
  int uniqueLetterString(string S) {
    const int mod = pow(10, 9) + 7;
    const int n = S.size();
    // all uppercase
    vector<vector<int>> index(26, vector<int>(2, -1));

    int ret = 0;
    for (int i = 0; i < n; i++) {
      int cur = S[i] - 'A';
      ret = (ret + (i - index[cur][1]) * (index[cur][1] - index[cur][0]) % mod) % mod;

      index[cur][0] = index[cur][1];
      index[cur][1] = i;
    }
    for (int i = 0; i < 26; i++) {
      ret = (ret + (n - index[i][1]) * (index[i][1] - index[i][0]) % mod) % mod;
    }

    return ret;
  }
};
