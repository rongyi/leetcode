// https://leetcode.com/problems/maximum-tastiness-of-candy-basket/
#include "xxx.hpp"

class Solution {
public:
  int maximumTastiness(vector<int> &price, int k) {
    sort(price.begin(), price.end());
    int l = 0;
    int r = 1e9;
    while (l < r) {
      auto mid = l + (r - l) / 2;
      // mid as minimum difference
      // and check how many we  can pick
      // if we can pick more than k
      // we shrink the minimum diff value
      // else we enlarge
      if (check(mid, price, k)) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }

    return l - 1;
  }

private:
  bool check(int val, vector<int> &price, int k) {
    int cnt = 1;
    int last_idx = 0;
    int cur_idx = 1;
    // pick numer which their diff is >= val
    while (cur_idx < price.size() && cnt < k) {
      if (price[cur_idx] - price[last_idx] >= val) {
        last_idx = cur_idx;
        cnt++;
      }
      cur_idx++;
    }

    return cnt == k;
  }
};
