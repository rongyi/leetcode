// http://leetcode.com/problems/di-string-match/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> diStringMatch(string S) {
    const int n = S.size();
    int left = 0;
    int right = n;
    vector<int> ret{};
    int last = 0;

    for (auto c : S) {
      if (c == 'I') {
        ret.push_back(left);
        left++;
        last = left;
      } else {
        ret.push_back(right);
        right--;
        last = right;
      }
    }

    ret.push_back(last);

    return ret;
  }
};
