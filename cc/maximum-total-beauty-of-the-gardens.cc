// https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/
#include "xxx.hpp"

class Solution {
public:
  long long maximumBeauty(vector<int> &flowers, long long newFlowers,
                          int target, int full, int partial) {
    sort(flowers.begin(), flowers.end());
    int sz = flowers.size();
    int full_cnt = 0;
    for (int i = sz - 1; i >= 0; --i) {
      if (flowers[i] < target) {
        break;
      }
      full_cnt++;
    }
    int max_fill_sz = sz - full_cnt;
    if (max_fill_sz == 0) {
      return (long long)full_cnt * full;
    }
    vector<long long> fill_up(max_fill_sz, 0);
    vector<long long> fill_to_target(max_fill_sz, 0);

    // from start, count what we need to fill to index i,
    // and each num is equal to flowers[i]
    for (int i = 1; i < max_fill_sz; ++i) {
      fill_up[i] = fill_up[i - 1] + i * (flowers[i] - flowers[i - 1]);
    }
    // use num at end, and fill each to target
    fill_to_target[max_fill_sz - 1] =
        (long long)target - flowers[max_fill_sz - 1];
    for (int i = max_fill_sz - 2; i >= 0; i--) {
      fill_to_target[i] =
          fill_to_target[i + 1] + (long long)(target - flowers[i]);
    }
    long long ret = 0;
    for (int num_fill = 0; num_fill <= max_fill_sz; ++num_fill) {
      long long partial_count = 0;
      long long remain_flower = newFlowers;
      if (num_fill != 0) {
        // nice
        remain_flower -= fill_to_target[max_fill_sz - num_fill];
      }
      if (remain_flower < 0) {
        break;
      }
      // there are patial pile
      if (num_fill != max_fill_sz) {
        auto it = upper_bound(fill_up.begin(), fill_up.end(), remain_flower);
        int idx = it - fill_up.begin();
        if (idx >= (max_fill_sz - num_fill)) {
          idx = max_fill_sz - num_fill;
        }
        // idx - 1 is the right most pile which not to target height
        partial_count = flowers[idx - 1];
        // https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/discuss/1931056/C%2B%2B-Iterate-over-number-of-gardens-we-make-full-then-Binary-Search
        // https://leetcode.com/problems/maximum-total-beauty-of-the-gardens/discuss/1931085/Python-Explanation-with-pictures-Greedy.
        // graph is in the second link
        partial_count += (remain_flower - fill_up[idx - 1]) / idx;
        partial_count = min(partial_count, (long long)target - 1);
      }

      long long cur =
          partial_count * partial + (full_cnt + num_fill) * (long long)full;
      ret = max(ret, cur);
    }
    return ret;
  }
};
