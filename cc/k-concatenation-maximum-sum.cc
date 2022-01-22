// http://leetcode.com/problems/k-concatenation-maximum-sum/description/
#include "xxx.hpp"

class Solution {
public:
  // https://leetcode.com/problems/k-concatenation-maximum-sum/discuss/382429/C%2B%2B-O(N)-time-O(1)-space-with-ExplanationPicture
  int kConcatenationMaxSum(vector<int> &arr, int k) {
    const int mod = pow(10, 9) + 7;

    int cur_max = numeric_limits<int>::min();
    int max_seen = numeric_limits<int>::min();
    int cur_min = numeric_limits<int>::max();
    int min_seen = numeric_limits<int>::max();

    for (auto x : arr) {
      cur_max = max(cur_max % mod + (x % mod), x);
      max_seen = max(max_seen, cur_max);

      cur_min = min(cur_min % mod + (x % mod), x);
      min_seen = min(cur_min, min_seen);
    }
    int totalk = 0;
    auto totalone = accumulate(arr.begin(), arr.end(), 0);
    for (int i = 0; i < k; ++i) {
      totalk = (totalk + (totalone % mod)) % mod;
    }

    int total_max = totalk;
    // remove from head
    for (int i = 0; i < arr.size(); ++i) {
      total_max = max(total_max, totalk - arr[i]);
      totalk -= arr[i];
    }

    // remove from tail
    int remove_front = total_max;
    for (int i = arr.size() - 1; i >= 0; --i) {
      total_max = max(total_max, remove_front - arr[i]);
      remove_front -= arr[i];
    }

    return max(max_seen, max(total_max, totalone - min_seen));
  }
};
