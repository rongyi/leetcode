// http://leetcode.com/problems/beautiful-arrangement-ii/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> constructArray(int n, int k) {
    vector<int> ret;
    int i = 1;
    int j = n;
    // n = 8, k = 3; res = [1 8 2 3 4 5 6 7] k:[7, 6, 1, ,1 ,1, 1, 1]
    // n = 8, k = 4; res = [8 1 7 2 3 4 5 6]; k[7, 6, 5, 1,1, 1, 1]
    // n = 8, k = 7; res = [8 1 7 2 6 3 5 4] ; k: [7 6 5 4 3 2 1]
    while (i <= j) {
      if (k > 1) {
        ret.push_back(k-- % 2 ? i++ : j--);
      } else {
        ret.push_back(i++);
      }
    }

    return ret;
  }
};
