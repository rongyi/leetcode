// http://leetcode.com/problems/leetcode/integer-to-roman/description/
#include "xxx.hpp"
class Solution {
public:
  string intToRoman(int n) {
    vector<pair<int, string>> base{
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"},
        {90, "XC"},  {50, "L"},   {40, "XL"}, {10, "X"},   {9, "IX"},
        {5, "V"},    {4, "IV"},   {1, "I"}};
    string ret;
    for (auto &b : base) {
      int repeat = n / b.first;
      n %= b.first;
      while (repeat--) {
        ret += b.second;
      }
    }

    return ret;
  }
};
