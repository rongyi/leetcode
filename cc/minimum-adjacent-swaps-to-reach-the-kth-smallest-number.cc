// http://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/discuss/1186818/C%2B%2B-Detailed-explanation-using-next_permutation
  int getMinSwaps(string num, int k) {
    string origin = num;
    while (k--) {
      next_permutation(num.begin(), num.end());
    }

    return count_step(origin, num);
  }

private:
  int count_step(string &s1, string &s2) {
    int size = s1.length();
    int i = 0;
    int j = 0;
    int ret = 0;

    while (i < size) {
      j = i;

      while (s1[i] != s2[j]) {
        j++;
      }
      // now two same we swap
      while (i < j) {
        swap(s2[j], s2[j - 1]);
        j--;
        ret++;
      }

      i++;
    }
    return ret;
  }
};
