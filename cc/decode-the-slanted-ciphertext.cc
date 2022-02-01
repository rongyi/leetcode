// https://leetcode.com/problems/decode-the-slanted-ciphertext/
#include "xxx.hpp"

class Solution {
public:
  string decodeCiphertext(string encodedText, int rows) {
    int sz = encodedText.size();
    const int cols = sz / rows;
    string ret{};
    int dlen = 0;
    int i = 0;
    int shift = 0;
    while (dlen < sz) {
      // i, j ==> i * cols + j
      int idx = i * cols + i + shift;
      if (idx < sz) {
        ret.push_back(encodedText[idx]);
      } else {
        // out of the range, we visit the last one
        break;
      }
      i++;
      if (i == rows) {
        shift++;
        i = 0;
      }
      dlen++;
    }
    while (ret.back() == ' ') {
      ret.pop_back();
    }

    return ret;
  }
};
