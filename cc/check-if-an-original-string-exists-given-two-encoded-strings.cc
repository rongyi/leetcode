// https://leetcode.com/problems/check-if-an-original-string-exists-given-two-encoded-strings/
#include "xxx.hpp"

class Solution {
public:
  // i: current index in s1
  // j: current index in s2
  // diff: distance *after* expand wildcard string
  // think like this: wildcard in s1 make diff more small
  // wildcard in s2 will make diff more bigger
  // they streach each other and will eventually be zero at last
  // *iif* the two string have an origin string
  bool possiblyEquals(string s1, string s2, int i = 0, int j = 0,
                      int diff = 0) {
    auto processDigits = [&](const string &s, int &p, int sign) -> bool {
      for (int val = 0; p < s.size() && isdigit(s[p]);) {
        val = val * 10 + (s[p] - '0');
        // p point to i, when sign is negative
        // p point to j when sign is postive
        // so we increase pointer at here!
        p += 1;
        if (possiblyEquals(s1, s2, i, j, diff + val * sign)) {
          return true;
        }
      }
      return false;
    };

    // when all => end, they must have euqal size
    if (i == s1.size() && j == s2.size()) {
      return diff == 0;
    }
    // shift diff to postive namespace
    if (!visited[i][j][1000 + diff]) {
      visited[i][j][1000 + diff] = true;
      if (i < s1.size() && isdigit(s1[i])) {
        return processDigits(s1, i, -1);
      }
      if (j < s2.size() && isdigit(s2[j])) {
        return processDigits(s2, j, 1);
      }
      if (diff > 0) {
        // then s1 must catch up, so we increase i pointer
        return i < s1.size() && possiblyEquals(s1, s2, i + 1, j, diff - 1);
      }
      if (diff < 0) {
        // then s2 mut catch up, so we increase j pointer
        return j < s2.size() && possiblyEquals(s1, s2, i, j + 1, diff + 1);
      }
      // the two non digit number must match, and after i, j, they must match as
      // well.
      return i < s1.size() && j < s2.size() && s1[i] == s2[j] &&
             possiblyEquals(s1, s2, i + 1, j + 1, diff);
    }

    return false;
  }

private:
  // 1 <= s1.length, s2.length <= 40
  // consecutive digits in s1 and s2 does not exceed 3.
  // so the diff between s1, s2 abs(diff) < 1000
  // we shift the negative value to 0 - 1000 range
  bool visited[41][41][2000] = {};
};
int main() {
  Solution so;
  cout << so.possiblyEquals("13", "xxxxxxxxxxxxx") << endl;
}
