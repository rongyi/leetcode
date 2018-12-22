// http://leetcode.com/problems/h-index-ii/description/
#include "xxx.h"

class Solution {
public:
  // clang-format off
  // case 1: citations[mid] == len-mid, then it means there are citations[mid] papers that have at least citations[mid] citations.
  // case 2: citations[mid] > len-mid, then it means there are citations[mid] papers that have moret than citations[mid] citations, so we should continue searching in the left half
  // case 3: citations[mid] < len-mid, we should continue searching in the right side
  // clang-format on
  int hIndex(vector<int> &citations) {
    int left = 0, len = citations.size(), right = len - 1, mid;
    while (left <= right) {
      mid = left + (right - left) / 2;
      if (citations[mid] == (len - mid)) {
        return citations[mid];
      } else if (citations[mid] > (len - mid)) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
    }
    return len - (right + 1);
  }
};
