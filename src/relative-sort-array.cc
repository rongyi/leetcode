// http://leetcode.com/problems/relative-sort-array/description/
#include "xxx.h"

class Solution {
public:
  vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, int> index;
    for (int i = 0; i < arr2.size(); ++i) {
      index[arr2[i]] = i;
    }
    auto getindex = [&index](int num) -> int {
      if (index.find(num) == index.end()) {
        return numeric_limits<int>::max();
      }
      return index[num];
    };

    sort(arr1.begin(), arr1.end(),
         [&getindex](int l1, int l2) { return getindex(l1) < getindex(l2); });

    int first_not_exist = -1;
    for (int i = 0; i < arr1.size(); ++i) {
      if (index.find(arr1[i]) == index.end()) {
        first_not_exist = i;
        break;
      }
    }
    if (first_not_exist != -1) {
      sort(arr1.begin() + first_not_exist, arr1.end());
    }
    return arr1;
  }
};
