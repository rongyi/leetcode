// http://leetcode.com/problems/check-if-n-and-its-double-exist/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkIfExist(vector<int> &arr) {
    unordered_set<double> uniq;
    for (int i = 0; i < arr.size(); i++) {
      if (uniq.find(arr[i] / 2.0) != uniq.end() ||
          uniq.find(arr[i] * 2.0) != uniq.end()) {
        return true;
      }
      uniq.insert(arr[i]);
    }
    return false;
  }
};
