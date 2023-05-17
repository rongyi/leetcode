// http://leetcode.com/problems/verify-preorder-serialization-of-a-binary-tree/description/
#include "xxx.hpp"

class Solution {
public:
  // When adding a non-NULL node, it means we obtains two more leafs, then
  // capacity +=2
  bool isValidSerialization(string preorder) {
    if (preorder.empty()) {
      return false;
    }
    preorder += ",";
    // number of nodes that can be put in the tree,
    // initial value is 1, means there is one knot
    // to put root node
    int capacity = 1;
    const int n = preorder.size();
    for (int i = 0; i < n; i++) {
      if (preorder[i] != ',') {
        continue;
      }
      // when we meet ',', there is a consume for capacity
      capacity--;

      if (capacity < 0) {
        return false;
      }

      // if previous node is not null,
      // then the node give two more capacity
      if (preorder[i - 1] != '#') {
        capacity += 2;
      }
    }

    return capacity == 0;
  }
};
