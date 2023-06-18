// https://leetcode.com/problems/find-the-substring-with-maximum-cost/
#include "xxx.hpp"

class Solution {
public:
  int maximumCostSubstring(string s, string chars, vector<int> &vals) {
    set<char> black;
    int sz = s.size();

    vector<int> score(26, 0);
    iota(score.begin(), score.end(), 1);
    for (int i = 0; i < chars.size(); i++) {
      // update postive value
      score[chars[i] - 'a'] = vals[i];
    }

    // remind you the subarray maximum sum in O(n)
    vector<int> toval(s.size(), 0);
    for (int i = 0; i < sz; i++) {
      toval[i] = score[s[i] - 'a'];
    }
    int acc = 0;
    int ret = 0;
    for (int i = 0; i < sz; i++) {
      acc += toval[i];
      if (acc < 0) {
        acc = 0;
      }
      ret = max(ret, acc);
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-1000};
  so.maximumCostSubstring("adaa", "d", input);
}
