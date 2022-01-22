// http://leetcode.com/problems/check-if-the-sentence-is-pangram/description/
#include "xxx.hpp"

class Solution {
public:
  bool checkIfPangram(string sentence) {
    vector<int> count(26, 0);

    for (auto c : sentence) {
      count[c - 'a']++;
    }
    for (auto cur : count) {
      if (cur == 0) {
        return false;
      }
    }

    return true;
  }
};
