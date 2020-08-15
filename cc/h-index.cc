// http://leetcode.com/problems/h-index/description/
#include "xxx.h"

class Solution {
public:
  // https://leetcode.com/problems/h-index/discuss/70768/Java-bucket-sort-O(n)-solution-with-detail-explanation
  int hIndex(vector<int> &citations) {
    const int n = citations.size();
    // 先作个统计
    vector<int> hindex(n + 1, 0);
    for (auto i : citations) {
      if (i >= n) {
        hindex[n]++;
      } else {
        hindex[i]++;
      }
    }

    // 从后往前
    int total = 0;
    for (int i = n; i >= 0; i--) {
      total += hindex[i];
      if (total >= i) {
        return i;
      }
    }
    return 0;
  }
};
