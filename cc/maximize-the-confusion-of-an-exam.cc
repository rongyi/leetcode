// https://leetcode.com/problems/maximize-the-confusion-of-an-exam/
#include "xxx.hpp"

class Solution {
public:
  int maxConsecutiveAnswers(string s, int k) {
    return max(count(s, k, 'T'), count(s, k, 'F'));
  };

private:
  // sliding window with at most k 'c' c in 'T' or 'F'
  // find maximum substring of 'T' which contains at most k 'F' or
  // maximum substring of 'F' which contains at most k 'T'.
  int count(string &s, int k, char c) {
    int sz = s.size();
    int cnt = 0;
    int i = 0;
    int ret = 0;

    for (int j = 0; j < sz; ++j) {
      cnt += s[j] == c;

      // ok, need shrink,
      // make cnt drop to k
      while (cnt > k) {
        cnt -= s[i++] == c;
      }

      // check every valid sliding window to get the maximum size
      ret = max(ret, j - i + 1);
    }
    return ret;
  }
};

int main() {
  Solution so;
  int ret = so.maxConsecutiveAnswers("TFFF", 2);
  cout << ret << endl;
}
