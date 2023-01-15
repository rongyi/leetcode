// https://leetcode.com/problems/categorize-box-according-to-criteria/
#include "xxx.hpp"

class Solution {
public:
  string categorizeBox(int length, int width, int height, int mass) {
    long long volume = (long long)length * width * height;
    vector<string> atribts;
    if (length >= 1e4 || width >= 1e4 || height >= 1e4 || volume >= 1e9) {
      atribts.push_back("Bulky");
    }
    if (mass >= 100) {
      atribts.push_back("Heavy");
    }
    if (atribts.size() == 2) {
      return "Both";
    } else if (atribts.size() == 0) {
      return "Neither";
    }
    return atribts[0];
  }
};
