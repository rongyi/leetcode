// http://leetcode.com/problems/find-common-characters/description/
#include "xxx.h"

class Solution {
public:
  vector<string> commonChars(vector<string> &A) {
    const int n = A.size();
    vector<vector<int>> count(n, vector<int>(26, 0));
    for (int i = 0; i < n; i++) {
      for (auto c : A[i]) {
        ++count[i][c - 'a'];
      }
    }
    vector<string> ret;
    for (int j = 0; j < 26; j++) {
      int cur_count = numeric_limits<int>::max();
      int i = 0;
      for (; i < n; i++) {
        cur_count = min(cur_count, count[i][j]);
        if (cur_count == 0) {
          break;
        }
      }
      for (int r = 0; r < cur_count; r++) {
        ret.push_back(string(1, j + 'a'));
      }
    }

    return ret;
  }
};
