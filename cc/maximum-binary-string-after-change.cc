// http://leetcode.com/problems/maximum-binary-string-after-change/description/
#include "xxx.h"

class Solution {
public:
  // 00 -> 10
  // 10 -> 01
  // 01111...10 -> 1011...1 被0夹住，可以一直这么把0往左移，这样最高位可以变成1
  // 题目没意思，得看出规律才行
  string maximumBinaryString(string binary) {
    if (binary.size() == 1) {
      return binary;
    }
    int left = 0;
    int right = 1;
    while (right < binary.size()) {
      if (binary[left] == '0' && binary[right] == '0') {
        binary[left] = '1';
        binary[right] = '1';
        binary[left + 1] = '0';
        left = left + 1;
        right = right + 1;
      } else if (binary[left] == '1') {
        left++;
        right = left + 1;
      } else {
        right++;
      }
    }

    return binary;
  }
};
