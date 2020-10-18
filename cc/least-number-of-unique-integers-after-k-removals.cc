// http://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/description/
#include "xxx.h"

class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int> &arr, int k) {
    unordered_map<int, int> count;
    for (auto num : arr) {
      count[num]++;
    }
    vector<int> uniq;
    for (auto &kv : count) {
      uniq.push_back(kv.first);
    }
    sort(uniq.begin(), uniq.end(),
         [&count](int &l, int &r) -> bool { return count[l] < count[r]; });
    int i = 0;
    while (k > 0) {
      if (k >= count[uniq[i]]) {
        k -= count[uniq[i]];
        i++;
      } else {
        break;
      }
    }

    return uniq.size() - i;
  }
};
