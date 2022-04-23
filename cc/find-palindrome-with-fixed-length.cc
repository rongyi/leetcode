// https://leetcode.com/problems/find-palindrome-with-fixed-length/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/find-palindrome-with-fixed-length/discuss/1886915/Formula
  vector<long long> kthPalindrome(vector<int> &queries, int sz) {
    vector<long long> ret;
    // count the middle in
    // e.g. 7 we count mid in and we need the left and mid total 4 digits
    long long start = pow(10, (sz + 1) / 2 - 1);
    // exclude
    long long end = pow(10, (sz + 1) / 2);
    // 'append' the right part, we need to shift the first part
    long long mul = pow(10, sz / 2);
    for (auto q : queries) {
      // q index start at 1
      if (start + q > end) {
        ret.push_back(-1);
      } else {
        long long left_part = start + q - 1;
        string s = to_string(left_part);
        if (sz & 1) {
          s.pop_back();
        }
        reverse(s.begin(), s.end());
        if (s.size()) {
          ret.push_back(left_part * mul + stoll(s));
        } else {
          // edge case of single digit
          ret.push_back(left_part * mul);
        }
      }
    }

    return ret;
  }
};
