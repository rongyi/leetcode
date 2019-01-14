// http://leetcode.com/problems/pascals-triangle-ii/description/
#include "xxx.h"

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> row(rowIndex + 1, 1);
    // consider this:
    //  1 3 3 1 0
    //+ 0 1 3 3 1
    // --------------
    //= 1 4 6 4 1
    for (int i = 1; i <= rowIndex; ++i) {
      int prev = 1;
      for (int j = 1; j < i; j++) {
        auto tmp = row[j];
        row[j] += prev;
        prev = tmp;
      }
    }
    return row;
  }
};
