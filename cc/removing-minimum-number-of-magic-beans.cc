// https://leetcode.com/problems/removing-minimum-number-of-magic-beans/
#include "xxx.hpp"

class Solution {
public:
  long long minimumRemoval(vector<int> &beans) {
    int sz = beans.size();
    sort(begin(beans), end(beans));
    long long ret = numeric_limits<long long>::max();
    // deletion from smallest to current, but not include current num
    // e.g. [1, 3, 7]
    // we get prev
    // 0, 1, 4
    long long prev = 0;
    vector<long long> prefix(sz + 1, 0);
    for (int i = 0; i < sz; ++i) {
      prefix[i + 1] = prefix[i] + beans[i];
    }

    for (int i = 0; i < sz;) {
      int j = i;
      // cast to long long
      long long cur = beans[i];
      while (j < sz && beans[j] == beans[i]) {
        j++;
      }
      // using iterator is a bit slower
      // auto it = upper_bound(beans.begin() , beans.end(), beans[i]);
      // int j = distance(beans.begin(), it);

      if (j == sz) {
        ret = min(ret, prev);
      } else {
        long long after_sum = prefix[sz] - prefix[j /* - 1 + 1*/];
        long long cur_delete = prev + after_sum - (sz - j) * cur;
        ret = min(cur_delete, ret);

        prev += (j - i) * cur;
      }
      i = j;
    }

    return ret;
  }
};
