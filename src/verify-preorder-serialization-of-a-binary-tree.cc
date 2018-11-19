// http://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
#include "simpleone.h"

class Solution {
public:
  bool isValidSerialization(string preorder) {
    if (preorder.empty()) {
      return false;
    }
    preorder += ",";
    int capacity = 1;
    const int n = preorder.size();
    for (int i = 0; i < n; i++) {
      if (preorder[i] != ',') {
        continue;
      }
      capacity--;
      if (capacity < 0) {
        return false;
      }
      if (preorder[i - 1] != '#') {
        capacity += 2;
      }
    }
    return capacity == 0;
  }
};
