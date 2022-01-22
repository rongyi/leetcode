// http://leetcode.com/problems/check-array-formation-through-concatenation/description/
#include "xxx.hpp"

class Solution {
public:
  bool canFormArray(vector<int> &arr, vector<vector<int>> &pieces) {
    map<int, int> first_num_index;
    for (int i = 0; i < pieces.size(); ++i) {
      first_num_index[pieces[i][0]] = i;
    }

    for (int i = 0; i < arr.size();) {
      if (first_num_index.find(arr[i]) == first_num_index.end()) {
        return false;
      }
      vector<int> &target = pieces[first_num_index[arr[i]]];
      // strict match
      for (int j = 0; j < target.size(); ++j, ++i) {
        if (target[j] != arr[i]) {
          return false;
        }
      }
    }

    return true;
  }
};
