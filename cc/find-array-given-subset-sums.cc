// https://leetcode.com/problems/find-array-given-subset-sums/
#include "xxx.hpp"

// https://leetcode.com/problems/find-array-given-subset-sums/discuss/1437739/Recursive-Disambiguation
class Solution {
public:
  vector<int> recoverArray(int n, vector<int> &s) {
    vector<int> ret;
    sort(s.begin(), s.end());
    while (s.size() > 1) {
      vector<int> l;
      vector<int> r;
      // either num or -num is in origin lst!
      int num = s[1] - s[0];
      bool l_zero = false;

      for (int i = 0, j = 0; i < s.size(); ++i) {
        if (s[i] != numeric_limits<int>::min()) {
          l_zero |= s[i] == 0;
          l.push_back(s[i]);
          r.push_back(s[i] + num);
          // mark the value that has been put to right
          // start from the next mark place(j + 1) or
          // the i + 1 (because we continue some i which is min_int case)
          // why not just start from i + 1?
          // because we also want ignore the prev min case, which
          // must > j
          for (j = max(j + 1, i + 1); s[j] != s[i] + num; ++j) {
          }
          s[j] = numeric_limits<int>::min();
        }
      }
      ret.push_back(num * (l_zero ? 1 : -1));
      swap(s, l_zero ? l : r);
    }

    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{-355, 0, 10, 44, 365, 399, 409, 764};
  so.recoverArray(3, input);
}
