// http://leetcode.com/problems/squares-of-a-sorted-array/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> sortedSquares(vector<int> &A) {
    sort(A.begin(), A.end(), [](int &l, int &r) { return abs(l) < abs(r); });
    for (auto &num : A) {
      num *= num;
    }
    return A;
  }
};
