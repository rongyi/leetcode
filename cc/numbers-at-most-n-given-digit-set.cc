// http://leetcode.com/problems/numbers-at-most-n-given-digit-set/description/
#include "xxx.h"

class Solution {
public:
  int atMostNGivenDigitSet(vector<string> &D, int N) {
    // https://leetcode.com/problems/numbers-at-most-n-given-digit-set/discuss/168439/C%2B%2B-O(logN)-Clear-code-with-explanation
    // Take N = 2563, D = {"1", "2", "6"} as an example,
    // The first loop handles the count of x, xx, xxx which x belongs to D. the
    // sum is 3^1 + 3^2 + 3^3. The second loop handles xxxx from left most
    // digit. For example, count of 1xxx is 3^3 count of 21xx is 3^2 count of
    // 22xx is 3^2

    // If the elements of D can compose entired N, answer + 1
    // Although it could be coded in a single loop, the logic would be unclear
    // to me. I keep them seperated.
    string ns = to_string(N);
    const int digits = ns.size();
    const int n = D.size();
    int ret = 0;

    // The first loop handles the count of x, xx, xxx which x belongs to D. the
    // sum is 3^1 + 3^2 + 3^3.
    for (int i = 1; i < digits; i++) {
      ret += pow(n, i);
    }

    for (int i = 0; i < digits; i++) {
      bool has_same_num = false;
      for (auto &s : D) {
        if (s[0] < ns[i]) {
          ret += pow(n, digits - i - 1);
        } else if (s[0] == ns[i]) {
          has_same_num = true;
        }
      }

      if (!has_same_num) {
        return ret;
      }
    }

    return ret + 1;
  }
};
