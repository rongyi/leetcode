// http://leetcode.com/problems/utf-8-validation/description/
#include "xxx.hpp"

class Solution {
public:
  bool validUtf8(vector<int> &data) {
    // edit the input
    vector<uint8_t> input;
    for (auto i : data) {
      input.push_back(uint8_t(i & 0xFF));
    }
    const int n = input.size();

    for (int i = 0; i < n; i++) {
      // as a single bit
      if (iszero(input[i])) {
        continue;
      }

      auto one_len = checkone(input[i]);
      // two short or too long
      // UTF8 can be from 1 to 4 bytes long
      if (one_len < 2 || one_len > 4 || one_len > n - i) {
        return false;
      }
      // then check the rest all 10
      for (int j = i + 1; j < i + one_len; j++) {
        if ((input[j] & 0x80) != 0x80) {
          return false;
        }
      }
      // the body has plus one, so we minus one to fit i++
      i += one_len - 1;
    }
    return true;
  }
public:
  // highest is zero?
  bool iszero(uint8_t &i) {
    return (i & 0x80) == 0x00;
  }
  int checkone(uint8_t &i) {
    int ret = 0;
    int j = 7;
    for (; j >= 0; j--) {
      auto cmp = ((1 << j) & i) >> j;
      if (cmp == 1) {
        ret++;
      } else {
        break;
      }
    }
    return ret;
  }
};

int main() {
  Solution so;
  vector<int>  input{250,145,145,145,145};
  auto ret = so.validUtf8(input);
  cout << ret << endl;
}
