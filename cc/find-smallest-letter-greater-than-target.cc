// http://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
#include "xxx.hpp"

class Solution {
public:
  char nextGreatestLetter(vector<char> &letters, char target) {
    for (auto ch : letters) {
      if (target < ch) {
        return ch;
      }
    }
    return letters[0];
  }
};
