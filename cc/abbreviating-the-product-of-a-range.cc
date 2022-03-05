// https://leetcode.com/problems/abbreviating-the-product-of-a-range/
#include "xxx.hpp"

class Solution {
public:
  string abbreviateProduct(int left, int right) {
    using ll = long long;
    ll suff = 1;
    ll zero_count = 0;
    ll total_digit = 0;
    ll max_suff = 1e11;
    double pref = 1.0;
    for (int i = left; i <= right; ++i) {
      pref *= i;
      suff *= i;
      // just pick the top 5 digit
      while (pref >= 1e5) {
        pref /= 10;
        // and count the total by the way
        total_digit = (total_digit == 0) ? 6 : total_digit + 1;
      }
      // keep suff no ending zero
      while (suff % 10 == 0) {
        suff /= 10;
        ++zero_count;
      }

      // make suff just enough digits
      suff %= max_suff;
    }
    string s = to_string(suff);

    ll real_num = total_digit - zero_count;
    return to_string((int)pref) + (real_num <= 10 ? "" : "...") +
           (real_num < 5 ? "" : s.substr(s.size() - min(5ll, real_num - 5))) +
           "e" + to_string(zero_count);
  }
};
