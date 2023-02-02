// http://leetcode.com/problems/regular-expression-matching/description/
#include "xxx.hpp"

class Solution {
public:
  bool isMatch(string s, string p) {
    ssz_ = s.size();
    psz_ = p.size();
    dp_ = vector<vector<int>>(ssz_ + 1, vector<int>(psz_ + 1, -1));

    return isMatch(s, 0, p, 0);
  }

private:
  bool isMatch(string &s, int i, string &p, int j) {
    if (dp_[i][j] != -1) {
      return dp_[i][j];
    }
    if (j == psz_) {
      if (i == ssz_) {
        dp_[i][j] = 1;
      } else {
        dp_[i][j] = 0;
      }
      return dp_[i][j];
    }
    if (j + 1 < psz_ && p[j + 1] == '*') {
      int val = isMatch(s, i, p, j + 2) ||
                (i < ssz_ && (s[i] == p[j] || p[j] == '.') &&
                 isMatch(s, i + 1, p, j));
      dp_[i][j] = val;
      if (val) {
        return dp_[i][j];
      }
    }
    if (i < ssz_ && (s[i] == p[j] || p[j] == '.')) {
      int val = isMatch(s, i + 1, p, j + 1);
      dp_[i][j] = val;
      if (val) {
        return dp_[i][j];
      }
    }

    return dp_[i][j] = 0;
  }

private:
  int ssz_;
  int psz_;
  vector<vector<int>> dp_;
};

int main() {
  Solution so;
  auto ret = so.isMatch("aab", "c*a*b");
  cout << ret << endl;
}
