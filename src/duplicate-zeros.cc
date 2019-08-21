// http://leetcode.com/problems/duplicate-zeros/description/
#include "xxx.h"

class Solution {
public:
  void duplicateZeros(vector<int> &arr) {
    const int n = arr.size();
    for (int i = 0; i < n; i++) {
      if (arr[i] == 0) {
        for (int j = n - 1; j > i; --j) {
          arr[j] = arr[j - 1];
        }
        // ignore the next 0
        i++;
      }
    }
  }
};
