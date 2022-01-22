// https://leetcode.com/problems/find-missing-observations/
#include "xxx.hpp"

class Solution {
public:
  vector<int> missingRolls(vector<int> &rolls, int mean, int n) {
    using ll = long long;
    int msz = rolls.size();
    auto msum = accumulate(rolls.begin(), rolls.end(), 0ll);
    ll total_sum = mean * (msz + n);
    ll nsum = total_sum - msum;
    // sum not valid
    if (nsum > 6 * n || nsum < 1 * n) {
      return {};
    }
    vector<int> ret(n, nsum / n);
    // add the left to one num
    int tail = nsum % n;
    if (tail) {
      // e.g. tail = 7 and current num in ret is 4
      // we can not add 7 to a single num
      // we must split to multiple nums
      // this is how we split num
      int diff = 6 - ret.back();

      int i = 0;
      for (; i < ret.size() && i < tail / diff; ++i) {
        ret[i] += diff;
      }

      if (diff > 1 && tail % diff) {
        ret[i] += tail % diff;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int> input{4, 5, 6, 2, 3, 6, 5, 4, 6, 4, 5, 1, 6, 3, 1, 4,
                    5, 5, 3, 2, 3, 5, 3, 2, 1, 5, 4, 3, 5, 1, 5};
  auto m = so.missingRolls(input, 4, 40);
  cout << m.size() << endl;
}
