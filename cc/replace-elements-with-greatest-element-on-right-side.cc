// http://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/description/
#include "xxx.hpp"

class Solution {
public:
  vector<int> replaceElements(vector<int> &arr) {
    const int n = arr.size();
    int cur_max = arr[n - 1];

    arr[n - 1] = -1;
    for (int i = n - 2; i >= 0; i--) {
      auto tmp = arr[i];
      arr[i] = cur_max;
      cur_max = max(cur_max, tmp);
    }

    return arr;
  }
};
