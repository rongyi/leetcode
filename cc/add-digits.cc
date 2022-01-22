// http://leetcode.com/problems/add-digits/description/
#include "xxx.hpp"

class Solution {
public:
  int addDigitsCSWay(int num) {
    auto ls = digit(num);
    if (ls.size() == 1) {
      return ls[0];
    }
    return addDigitsCSWay(accumulate(ls.begin(), ls.end(), 0));
  }
  // the math way
  int addDigits(int num) { return (num - 1) % 9 + 1; }

private:
  vector<int> digit(int num) {
    if (num == 0) {
      return vector<int>{0};
    }
    vector<int> ret;
    while (num) {
      ret.push_back(num % 10);
      num /= 10;
    }

    return ret;
  }
};
