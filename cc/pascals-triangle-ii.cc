// http://leetcode.com/problems/pascals-triangle-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> prev{1};
    for (int i = 1; i <= rowIndex; i++) {
      vector<int> row{1};
      for (int j = 1; j < prev.size(); j++) {
        row.push_back(prev[j - 1] + prev[j]);
      }

      row.push_back(1);
      prev.swap(row);
    }

    return prev;
  }
};
