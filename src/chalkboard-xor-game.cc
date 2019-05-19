// http://leetcode.com/problems/chalkboard-xor-game/description/
#include "xxx.h"

class Solution {
public:
  //   Math:
  // Corner Case: If the XOR of all nums is 0, then A wins.

  // Now we discuss the more general cases where the input doesn't form the corner case.

  // Proposition: Suppose the current chalkboard is S and the len(S)=N, now it's player P's turn. P can always make a move iff XOR(S) != 0 and N is Even.

  // Proof:

  // Let X = XOR(S), when X != 0, at least one bit of X must be 1. Let bit 'b' of X be the bit. I.e., X[b] = 1.
  // Then we can divide the numbers in S into two groups: U and V, where numbers in U have 0 at bit b, and numbers in V have 1 at bit b.
  // Initially, len(U) could be even or odd, BUT len(V) must be odd, otherwise we wouldn't have X[b]=1. So len(U) must be odd too because of the following:
  // len(V)+len(U)=N
  // len(V) is odd
  // N is even
  // The fact len(U) is odd implies that there must be at least one number (say Y) in S which has Y[b]=0.
  // If player P removes the number Y from S, the result chalkboard S' will have X'= XOR(S') = X xor Y, where X'[b] = 1. So S' != 0.
  bool xorGame(vector<int> &nums) {
    int x = 0;
    for (auto num : nums) {
      x ^= num;
    }
    return x == 0 || nums.size() % 2 == 0;
  }
};
