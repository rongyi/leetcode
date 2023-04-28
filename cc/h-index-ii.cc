// http://leetcode.com/problems/h-index-ii/description/
#include "xxx.hpp"

class Solution {
public:
  // clang-format off
  // case 1: citations[mid] == len-mid, then it means there are citations[mid] papers that have at least citations[mid] citations.
  // case 2: citations[mid] > len-mid, then it means there are citations[mid] papers that have moret than citations[mid] citations, so we should continue searching in the left half
  // case 3: citations[mid] < len-mid, we should continue searching in the right side
  // clang-format on
  int hIndex(vector<int> &citations) {
    int sz = citations.size();
    int l = 0;
    int r = sz - 1;

    while (l <= r) {
      int mid = l + (r - l) / 2;
      int paper_cnt = sz - mid;
      if (paper_cnt == citations[mid]) {
        return paper_cnt;
      } else if (paper_cnt < citations[mid]) {
        // means we should increase paper
        // or lower citation bar
        // we go left
        r = mid - 1;
      } else {
        l = mid + 1;
      }
    }

    return sz - (r + 1);
  }
};
